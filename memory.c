#include <stdlib.h>
#include <stddef.h>

/**
<<<<<<< HEAD
 * freeAndNull - frees memory allocated to ptr and sets it to NULL
 * @ptr: pointer to the memory to be freed
=======
 * bfree - frees memory of ptr and NULL
 * @ptr: freed pointer destinattion
>>>>>>> 54350c2788c098abd28af1b50af1695d30af1197
 *
 * Return: 0 or 1 if freed
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
