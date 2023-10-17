#include <stdlib.h>
#include <unistd.h>
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == NULL)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}

/**
 * _strdup - Duplicates a string and allocates memory for it.
 * @str: The string to be duplicated.
 *
 * Return: Pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 * _puts - Writes a string to the standard output.
 * @str: The string to be written.
 *
 * Return: Nothing.
 */
void _puts(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}

/**
 * _putchar - Writes a character to the standard output.
 * @e: The character to be written.
 *
 * Return: On success, 1. On error, -1 is returned,
 * and eerrno is set appropriately.
 **/
