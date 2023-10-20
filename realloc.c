#include "shell.h"

/**
 * _memset - memory block to specific value
 * @m: pointer to memory
 * @q: byte to set
 * @b: byte amount
 * Return: memory s pointter
 */
char *_memset(char *m, char q, unsigned int b)
{
	unsigned int k;

	for (k = 0; k < b; k++)
		m[k] = q;
	return (m);
}

/**
 * ffree - string of memory reusable
 * @ff: strings str
 */
void ffree(char **ff)
{
	char **w = ff;

	if (!ff)
		return;
	while (*ff)
		free(*ff++);
	free(w);
}

/**
 * _realloc - block of memory resize
 * @ptr: previous malloc pointter
 * @old_size: previous block size
 * @new_size: new block size
 *
 * Return: pointer to old block name
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	a = malloc(new_size);
	if (!a)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		a[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (a);
}
