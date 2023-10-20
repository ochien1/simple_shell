#include "shell.h"

/**
 * add_node - adds node to list start
 * @head: address of head node pointer
 * @str: field of node str
 * @num: history node index
 *
 * Return: list size
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - adds node to end of  list
 * @head: pointer to head node address
 * @str: str field node
 * @num: history node index
 *
 * Return: list size
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *nodee;

	if (!head)
		return (NULL);

	nodee = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (nodee)
	{
		while (nodee->next)
			nodee = nodee->next;
		nodee->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - prints str element of list_t linked
 * @r: first node pointer
 *
 * Return: list size
 */
size_t print_list_str(const list_t *r)
{
	size_t m = 0;

	while (r)
	{
		_puts(r->str ? r->str : "(nil)");
		_puts("\n");
		r = r->next;
		m++;
	}
	return (m);
}

/**
 * delete_node_at_index - delete node at index
 * @head: pointer to first node address
 * @index: index of delete node
 *
 * Return: 0 on failurre1 on success
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *nodee, *prev_node;
	unsigned int m = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		nodee = *head;
		*head = (*head)->next;
		free(nodee->str);
		free(nodee);
		return (1);
	}
	nodee = *head;
	while (nodee)
	{
		if (m == index)
		{
			prev_node->next = nodee->next;
			free(nodee->str);
			free(nodee);
			return (1);
		}
		m++;
		prev_node = nodee;
		nodee = nodee->next;
	}
	return (0);
}

/**
 * free_list - list node free
 * @head_ptr: pointer to head node address
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *nodee, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	nodee = head;
	while (nodee)
	{
		next_node = nodee->next;
		free(nodee->str);
		free(nodee);
		nodee = next_node;
	}
	*head_ptr = NULL;
}
