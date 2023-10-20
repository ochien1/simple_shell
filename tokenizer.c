#include "shell.h"

/**
 * **strtow - stttr splits to an word array
 * @str: input str
 * @x: delimeter str
 * Return: pointer to str array, or NULL on failure
 */

char **strtow(char *str, char *x)
{
	int w, b, a, f, numwords = 0;
	char **y;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!x)
		x = " ";
	for (w = 0; str[w] != '\0'; w++)
		if (!is_delim(str[w], x) && (is_delim(str[w + 1], x) || !str[w + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	y = malloc((1 + numwords) * sizeof(char *));
	if (!y)
		return (NULL);
	for (w = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(str[w], x))
			w++;
		a = 0;
		while (!is_delim(str[w + a], x) && str[w + a])
			a++;
		y[b] = malloc((a + 1) * sizeof(char));
		if (!y[b])
		{
			for (a = 0; a < b; a++)
				free(y[a]);
			free(y);
			return (NULL);
		}
		for (f = 0; f < a; f++)
			y[b][f] = str[w++];
		y[b][f] = 0;
	}
	y[b] = NULL;
	return (y);
}

/**
 * **strtow2 - split str to an word array
 * @str: input str
 * @x: delimeter
 * Return: NULL on failure or pointer to an str array
 */
char **strtow2(char *str, char x)
{
	int w, b, a, f, numwords = 0;
	char **y;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (w = 0; str[w] != '\0'; w++)
		if ((str[w] != x && str[w + 1] == x) ||
				    (str[w] != x && !str[w + 1]) || str[w + 1] == x)
			numwords++;
	if (numwords == 0)
		return (NULL);
	y = malloc((1 + numwords) * sizeof(char *));
	if (!y)
		return (NULL);
	for (w = 0, b = 0; b < numwords; b++)
	{
		while (str[w] == x && str[w] != x)
			w++;
		a = 0;
		while (str[w + a] != x && str[w + a] && str[w + a] != a)
			a++;
		y[b] = malloc((a + 1) * sizeof(char));
		if (!y[b])
		{
			for (a = 0; a < b; a++)
				free(y[a]);
			free(y);
			return (NULL);
		}
		for (f = 0; f < a; f++)
			y[b][f] = str[w++];
		y[b][f] = 0;
	}
	y[b] = NULL;
	return (y);
}
