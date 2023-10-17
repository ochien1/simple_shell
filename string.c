#include "shell.h"

/**
* _strlen_custom - returns the length of a string
* @str: the string whose length is to be measured
*
* Return: integer length of string
*/
int _strlen_custom(char *str)
{
int length = 0;

if (!str)
return (0);

while (*str++)
length++;
return (length);
}

/**
* _strcmp_custom - compares two strings lexicographically
* @str1: first string to compare
* @str2: second string to compare
*
* Return: negative if str1 < str2,
* positive if str1 > str2, zero if str1 == str2
*/
int _strcmp_custom(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}

/**
* starts_with_custom - finds the substring needle that starts with haystack
* @haystack: string to be searched
* @needle: the substring to be found
*
* Return: address of next character of haystack or NULL if not found
*/
char *starts_with_custom(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* _strcat_custom - concatenates two strings
* @dest: the destination buffer
* @src: the source buffer
*
* Return: pointer to destination buffer
*/
char *_strcat_custom(char *dest, char *src)
{
char *result = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (result);
}
