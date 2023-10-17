#include "shell.h"

/**
 * input_buf - chained commands
 * @info: struct parameter struct
 * @buf: buffer address
 * @len: len var address
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t m = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		m = getline(buf, &len_p, stdin);
#else
		m = _getline(info, buf, &len_p);
#endif
		if (m > 0)
		{
			if ((*buf)[m - 1] == '\n')
			{
				(*buf)[m - 1] = '\0';
				m--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = m;
				info->cmd_buf = buf;
			}
		}
	}
	return (m);
}

/**
 * get_input - minus the newline line
 * @info: struct parameter
 *
 * Return: bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t w, y, len;
	ssize_t m = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	m = input_buf(info, &buf, &len);
	if (m == -1)
		return (-1);
	if (len)
	{
		y = w;
		p = buf + w;

		check_chain(info, buf, &y, w, len);
		while (y < len)
		{
			if (is_chain(info, buf, &y))
				break;
			y++;
		}
		w = y + 1;
		if (w >= len)
		{
			w = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (m);
}

/**
 * read_buf - read buffer
 * @info: struct parameter
 * @buf: buffer
 * @w: size
 *
 * Return: m
 */
ssize_t read_buf(info_t *info, char *buf, size_t *w)
{
	ssize_t m = 0;

	if (*w)
		return (0);
	m = read(info->readfd, buf, READ_BUF_SIZE);
	if (m >= 0)
		*w = m;
	return (m);
}

/**
 * _getline - gets next line STDIN of input
 * @info: struct parameter
 * @ptr: buffer pointer address preallocated or NULL
 * @length:  if not NULL size of preallocated ptr buffer
 *
 * Return: d
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t w, len;
	size_t z;
	ssize_t m = 0, d = 0;
	char *p = NULL, *new_p = NULL, *f;

	p = *ptr;
	if (p && length)
		d = *length;
	if (w == len)
		w = len = 0;

	m = read_buf(info, buf, &len);
	if (m == -1 || (m == 0 && len == 0))
		return (-1);

	f = _strchr(buf + w, '\n');
	z = f ? 1 + (unsigned int)(f - buf) : len;
	new_p = _realloc(p, d, d ? d + z : z + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (d)
		_strncat(new_p, buf + w, z - w);
	else
		_strncpy(new_p, buf + w, z - w + 1);

	d += z - w;
	w = z;
	p = new_p;

	if (length)
		*length = d;
	*ptr = p;
	return (d);
}

/**
 * sigintHandler - ctrl-C blocker
 * @sig_num: signal no
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
