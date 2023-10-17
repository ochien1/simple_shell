#include "shell.h"

/**
 * get_history_file - histry file
 * @info: struct parameter
 *
 * Return: history file with allocated str
 */

char *get_history_file(info_t *info)
{
	char *buf, *dirr;

	dirr = _getenv(info, "HOME=");
	if (!dirr)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dirr) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dirr);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - append to an existing file or create file
 * @info: struct par
 *
 * Return: 1 on success otherwise -1
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - history file reader
 * @info: struct parameter
 *
 * Return: histcount or 0 otherwise
 */
int read_history(info_t *info)
{
	int m, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (m = 0; m < fsize; m++)
		if (buf[m] == '\n')
		{
			buf[m] = 0;
			build_history_list(info, buf + last, linecount++);
			last = m + 1;
		}
	if (last != m)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - history linked list entry
 * @info: structure with potential arguments. Used to maintain
 * @buf:  buffer
 * @linecount: the history, linecount and histcount
 *
 * Return: 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *nodee = NULL;

	if (info->history)
		nodee = info->history;
	add_node_end(&nodee, buf, linecount);

	if (!info->history)
		info->history = nodee;
	return (0);
}

/**
 * renumber_history - after changes renumbers the history linked list
 * @info: structure with potential arguments used to maintain
 *
 * Return: histcount
 */
int renumber_history(info_t *info)
{
	list_t *nodee = info->history;
	int m = 0;

	while (nodee)
	{
		nodee->num = m++;
		nodee = nodee->next;
	}
	return (info->histcount = m);
}
