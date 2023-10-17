#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: str to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int m = 0;

	if (!str)
		return;
	while (str[m] != '\0')
	{
		_eputchar(str[m]);
		m++;
	}
}

/**
 * _eputchar - char c to stderr writer
 * @r:  char 2 print
 *
 * Return: 1 on success,
 * on error -1 , and errno is set appropriately.
 */
int _eputchar(char r)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (r == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(2, buf, m);
		m = 0;
	}
	if (r != BUF_FLUSH)
		buf[m++] = r;
	return (1);
}

/**
 * _putfd - writes char c to fd
 * @r:  char 2 print
 * @fd:  file descriptor to write
 *
 * Return: 1 on success .
 * on error -1 , and errno is set appropriately.
 */
int _putfd(char r, int fd)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (r == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(fd, buf, m);
		m = 0;
	}
	if (r != BUF_FLUSH)
		buf[m++] = r;
	return (1);
}

/**
 *_putsfd - print to str input
 * @str: str to print
 * @fd:  file descriptor to write
 *
 * Return:  no of put chars
 */
int _putsfd(char *str, int fd)
{
	int m = 0;

	if (!str)
		return (0);
	while (*str)
	{
		m += _putfd(*str++, fd);
	}
	return (m);
}
