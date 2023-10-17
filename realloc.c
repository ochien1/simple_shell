#include "shell.h"

/**
 * _memset_custom - sets the block memory to a specified value
 * @s: the memory pointer
 * @b: the byte to set *s with
 * @n: the amount of bytes to be set
 * Return: (s) memory area s's pointer
 */
char *_memset_custom(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree_custom - makes memory a string of reusable
 * @pp: string of strings
 */
void ffree_custom(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc_custom - resizes a block of memory
 * @ptr: pointer to previous malloc'ated memory
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to the old block nameen.
 */
void *_realloc_custom(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
