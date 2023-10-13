#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: the address of pointer to head node
 * @str: a str field of node
 * @num: the node index used by history
 *
 * Return: the size of list
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
 * add_node_end - adding a node to the end of the list
 * @head: the address of pointer to head node
 * @str: a str field of node
 * @num: the node index used by history
 *
 * Return: the size of list
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
 * print_list_str - prints only the str element of a list_t linked list
 * @h: the pointer to first node
 *
 * Return: the size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		k++;
	}
	return (k);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: the address of pointer to first node
 * @index: the index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *nodee, *prev_node;
	unsigned int k = 0;

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
		if (k == index)
		{
			prev_node->next = nodee->next;
			free(nodee->str);
			free(nodee);
			return (1);
		}
		k++;
		prev_node = nodee;
		nodee = nodee->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: the address of pointer to head node
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
