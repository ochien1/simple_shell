#include "shell.h"

/**
 * interactive - tif sheell interactive true
 * @info: thee struct addreess
 *
 * Return:  0 otherwise 1 in interactive mode,
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - character delimeter checkers
 * @q: char to be  check
 * @delim: str delimeter
 * Return: 0 if false 1 if true,
 */
int is_delim(char q, char *delim)
{
	while (*delim)
		if (*delim++ == q)
			return (1);
	return (0);
}

/**
 *_isalpha - alphabetic char checker
 *@q: char 2 input
 *Return:  0 otherwise not1  q is alphabetic,
 */

int _isalpha(int q)
{
	if ((q >= 'a' && q <= 'z') || (q >= 'A' && q <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - str to integer converter
 *@y: string 2 converted
 *Return: 0 if no numbers in string or converted number
 */

int _atoi(char *y)
{
	int b, sign = 1, flag = 0, out;
	unsigned int t = 0;

	for (y = 0;  y[b] != '\0' && flag != 2; b++)
	{
		if (y[b] == '-')
			sign *= -1;

		if (y[b] >= '0' && y[b] <= '9')
		{
			flag = 1;
			t *= 10;
			t += (y[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		out = -t;
	else
		out = t;

	return (out);
}
