#include "shell.h"

/**
 * _strlen - length of a string
 * @w: str too measure
 *
 * Return: integer len of str
 */
int _strlen(char *w)
{
	int k = 0;

	if (!w)
		return (0);

	while (*w++)
		k++;
	return (k);
}

/**
 * _strcmp - compares two strings lexicographically
 * @sr1: start point
 * @sr2: ending point
 * Return: negative if s1 les sr2, positive if sr1
 * greater sr2, zero if sr1 equals sr2
 * _strcmp: buffer
 */
int _strcmp(char *sr1, char *sr2)
{
	while (*sr1 && *sr2)
	{
		if (*sr1 != *sr2)
			return (*sr1 - *sr2);
		sr1++;
		sr2++;
	}
	if (*sr1 == *sr2)
		return (0);
	else
		return (*sr1 < *sr2 ? -1 : 1);
}

/**
 * starts_with - finds needle in haystack
 * @haystack: str to search
 * @needle: substring to find
 *
 * Return: next char address or null
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - two strings link
 * @dest: buffer destination
 * @src: buffer source
 *
 * Return: destination buffer pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
