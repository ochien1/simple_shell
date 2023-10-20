#include "shell.h"

/**
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
}


/**
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
}
