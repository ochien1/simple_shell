#include <stdlib.h>
#include <stddef.h>

/**
 * freeAndNull - frees memory allocated to ptr and sets it to NULL
 * @ptr: pointer to the memory to be freed
 *
 * Return: 1 if freed, otherwise 0.
 */
int freeAndNull(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
