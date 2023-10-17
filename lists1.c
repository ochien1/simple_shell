#include "shell.h"

/**
<<<<<<< HEAD
* list_length - finds the length of a linked list
* @head: pointer to the first node
*
* Return: size of the list
*/
size_t list_length(const list_t *head)
{
size_t count = 0;

while (head)
{
head = head->next;
count++;
}
return (count);
}

/**
* list_to_strings - converts linked list to an array of strings
* @head: pointer to the first node
*
* Return: array of strings
*/
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t len = list_length(head);
char **strings;
char *str;

if (!head || len == 0)
return (NULL);

strings = malloc(sizeof(char *) * (len + 1));
if (!strings)
return (NULL);

for (size_t i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (size_t j = 0; j < i; j++)
free(strings[j]);
free(strings);
return (NULL);
}

str = _strcpy(str, node->str);
strings[i] = str;
=======
 * list_len - find length of linked list
 * @k: pointer to first node
 *
 * Return: list size
 */
size_t list_len(const list_t *k)
{
	size_t b = 0;

	while (k)
	{
		k = k->next;
		b++;
	}
	return (b);
}

/**
 * list_to_strings - convert string to array of strings
 * @head: pointer to first node
 *
 * Return: string array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t b = list_len(head), x;
	char **strs;
	char *str;

	if (!head || !b)
		return (NULL);
	strs = malloc(sizeof(char *) * (b + 1));
	if (!strs)
		return (NULL);
	for (b = 0; node; node = node->next, b++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (x = 0; x < b; x++)
				free(strs[x]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[b] = str;
	}
	strs[b] = NULL;
	return (strs);
>>>>>>> 54350c2788c098abd28af1b50af1695d30af1197
}

strings[len] = NULL;
return (strings);
}

/**
<<<<<<< HEAD
* print_list - prints all elements of a list_t linked list
* @head: pointer to the first node
*
* Return: size of the list
*/
size_t print_list(const list_t *head)
{
size_t count = 0;

while (head)
{
_puts(convert_number(head->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(head->str ? head->str : "(nil)");
_puts("\n");
head = head->next;
count++;
}

return (count);
}

/**
* find_node_starts_with - finds the node whose string starts with a prefix
* @head: pointer to the first node
* @prefix: string to be matched
* @e: next character to be matched after prefix
*
* Return: pointer to the matching node or NULL
*/
list_t *find_node_starts_with(list_t *head, char *prefix, char e)
{
char *p = NULL;

while (head)
{
p = starts_with(head->str, prefix);
if (p && ((e == -1) || (*p == e)))
return (head);
head = head->next;
}

return (NULL);
}

/**
* get_node_index - compares node pointers and gets the index of a node
* @head: pointer to the first node
* @node: pointer to the node
*
* Return: index of the node or -1 if not found
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t index = 0;

while (head)
{
if (head == node)
return (index);
head = head->next;
index++;
}

return (-1);
=======
 * print_list - prints all list_t linked list elements
 * @k: pointer to first node
 *
 * Return: list size
 */
size_t print_list(const list_t *k)
{
	size_t b = 0;

	while (k)
	{
		_puts(convert_number(k->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(k->str ? k->str : "(nil)");
		_puts("\n");
		k = k->next;
		b++;
	}
	return (b);
}

/**
 * node_starts_with - checks if string node starts with prefix
 * @node: pointer to head
 * @prefix: matched string
 * @f: next character to match after prefix
 *
 * Return: null or match node
 */
list_t *node_starts_with(list_t *node, char *prefix, char f)
{
	char *z = NULL;

	while (node)
	{
		z = starts_with(node->str, prefix);
		if (z && ((f == -1) || (*z == f)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index -  gets the index,compare node pointers
 * @head: pointer list head
 * @node: pointer to node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t b = 0;

	while (head)
	{
		if (head == node)
			return (b);
		head = head->next;
		b++;
	}
	return (-1);
>>>>>>> 54350c2788c098abd28af1b50af1695d30af1197
}
