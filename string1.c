#include "shell.h"

/**
 * _strcpy - copy of a string
 * @dest: end point @src: start point
 * @src: string to note
 * Return: destination pointer
 */
char *_strcpy(char *dest, char *src)
{
	int k = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;
	return (dest);
}

/**
 * _strdup - copy str, allocate memory
 * @str: str to copy
 *
 * Return: pointer to duplicated str
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - writes str to stdout
 * @str: str to write
 *
 * Return: ZERO
 */
void _puts(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_putchar(str[k]);
		k++;
	}
}

/**
 * _putchar - print char c to stdout
 * @f: char to print out
 *
 * Return: 1 on success
 * 0 on error, -1 is returned, and errno is set.
 */
int _putchar(char f)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (f == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(1, buf, k);
		k = 0;
	}
	if (f != BUF_FLUSH)
		buf[k++] = f;
	return (1);
}
