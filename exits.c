#include "shell.h"

/**
 **_strncpy - string copy
 *@dest: destination string
 *@src: source string
 *@a: characters amount
 *Return: concatenated str
 */
char *_strncpy(char *dest, char *src, int a)
{
	int w, z;
	char *s = dest;

	w = 0;
	while (src[w] != '\0' && w < a - 1)
	{
		dest[w] = src[w];
		w++;
	}
	if (w < a)
	{
		z = w;
		while (z < a)
		{
			dest[z] = '\0';
			z++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates strings
 *@dest: first string
 *@src: second string
 *@a: maximally used bytesamount
 *Return: concatenated str
 */
char *_strncat(char *dest, char *src, int a)
{
	int m, z;
	char *s = dest;

	m = 0;
	z = 0;
	while (dest[m] != '\0')
		m++;
	while (src[z] != '\0' && z < a)
	{
		dest[m] = src[z];
		m++;
		m++;
	}
	if (z < a)
		dest[m] = '\0';
	return (s);
}

/**
 **_strchr - locate char in str
 *@f: str to pars
 *@g: char to search
 *Return: (f) memory area pointer f
 */
char *_strchr(char *f, char g)
{
	do {
		if (*f == g)
			return (f);
	} while (*f++ != '\0');

	return (NULL);
}
