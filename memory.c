#include "shell.h"

/**
 * bfree - nulls and frees memory too pointer
 * @ptr: pointer free desttination
 *
 * Return: 0 or 1 if freed
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
