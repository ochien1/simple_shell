#include "shell.h"

/**
 * _erratoi - convert str to int
 * @w: convert str
 * Return: If no numbers in string 0 or converted number,
 *       -1 on error
 */
int _erratoi(char *w)
{
	int m = 0;
	unsigned long int result = 0;

	if (*w == '+')
		w++;
	for (m = 0;  w[m] != '\0'; m++)
	{
		if (w[m] >= '0' && w[m] <= '9')
		{
			result *= 10;
			result += (w[m] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - error message print
 * @info:  return and par info struct
 * @estr: str with spec error
 * Return: If no numbers in string 0,converted number or
 *        on error -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - print decimal fuction (number (base 10)
 * @input: input
 * @fd:  filedescriptor to write
 *
 * Return: no of characters print
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int m, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (m = 1000000000; m > 1; m /= 10)
	{
		if (_abs_ / m)
		{
			__putchar('0' + current / m);
			count++;
		}
		current %= m;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function itoa clone
 * @num: no
 * @base: base
 * @flags: arg flags
 *
 * Return: str
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arrayy;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long d = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		d = -num;
		sign = '-';

	}
	arrayy = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = arrayy[d % base];
		d /= base;
	} while (d != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function that replaces first instance of '#' with '\0'
 * @buf: modify str address
 *
 * Return: 0;
 */
void remove_comments(char *buf)
{
	int m;

	for (m = 0; buf[m] != '\0'; m++)
		if (buf[m] == '#' && (!m || buf[m - 1] == ' '))
		{
			buf[m] = '\0';
			break;
		}
}
