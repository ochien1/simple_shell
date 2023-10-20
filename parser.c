#include "shell.h"

/**
 * is_cmd - check iffile is exe
 * @info: rmationstruct info
 * @path: str par
 *
 * Return: 0 otherwise 1 if true
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - make char copy
 * @pathstr: strrr PATH
 * @start: index of source
 * @stop: desttination index
 *
 * Return: new buffer pointer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, z = 0;

	for (z = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[z++] = pathstr[x];
	buf[z] = 0;
	return (buf);
}

/**
 * find_path - full cmd search
 * @info: pointer to sttructt info
 * @pathstr: Path environmentt variable
 * @cmd: command to find
 *
 * Return: NULL or full path of cmd
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dup_chars(pathstr, curr_pos, x);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[x])
				break;
			curr_pos = x;
		}
		x++;
	}
	return (NULL);
}
