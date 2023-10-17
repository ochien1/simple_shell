#include "shell.h"

/**
 * bfree - frees memory of ptr and NULL
 * @ptr: freed pointer destinattion
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
