#include "shell.h"

/**
<<<<<<< HEAD
* add_node - adds a node to the start of the list
* @head: the address of pointer to head node
* @str_value: a string value for the node
* @node_index: the node index used by history
*
* Return: the new node
*/
list_t *add_node(list_t **head, const char *str_value, int node_index)
=======
 * add_node - adds node to list start
 * @head: address of head node pointer
 * @str: field of node str
 * @num: history node index
 *
 * Return: list size
 */
list_t *add_node(list_t **head, const char *str, int num)
>>>>>>> 54350c2788c098abd28af1b50af1695d30af1197
{
list_t *new_node;

if (!head)
return (NULL);

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = node_index;

if (str_value)
{
new_node->str = _strdup(str_value);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}

new_node->next = *head;
*head = new_node;
return (new_node);
}

/**
<<<<<<< HEAD
* add_node_end - adds a node to the end of the list
* @head: the address of pointer to head node
* @str_value: a string value for the node
* @node_index: the node index used by history
*
* Return: the new node
*/
list_t *add_node_end(list_t **head, const char *str_value, int node_index)
{
list_t *new_node, *current_node;

if (!head)
return (NULL);

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = node_index;

if (str_value)
{
new_node->str = _strdup(str_value);
if (!new_node->str)
=======
 * add_node_end - adds node to end of  list
 * @head: pointer to head node address
 * @str: str field node
 * @num: history node index
 *
 * Return: list size
 */
list_t *add_node_end(list_t **head, const char *str, int num)
>>>>>>> 54350c2788c098abd28af1b50af1695d30af1197
{
free(new_node);
return (NULL);
}
}

current_node = *head;
if (current_node)
{
while (current_node->next)
current_node = current_node->next;
current_node->next = new_node;
}
else
*head = new_node;

return (new_node);
}

/**
<<<<<<< HEAD
* print_list_str - prints only the str element of a list_t linked list
* @node: the pointer to first node
*
* Return: the number of nodes
*/
size_t print_list_str(const list_t *node)
{
size_t count = 0;

while (node)
{
_puts(node->str ? node->str : "(nil)");
_puts("\n");
node = node->next;
count++;
}

return (count);
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
list_t *current_node, *prev_node;
unsigned int count = 0;

if (!head || !*head)
return (0);

if (!index)
{
current_node = *head;
*head = (*head)->next;
free(current_node->str);
free(current_node);
return (1);
}

current_node = *head;
while (current_node)
{
if (count == index)
{
prev_node->next = current_node->next;
free(current_node->str);
free(current_node);
return (1);
}
count++;
prev_node = current_node;
current_node = current_node->next;
}

return (0);
}

/**
* free_list - frees all nodes of a list
* @head_ptr: the address of pointer to head node
*
* Return: void
*/
=======
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
>>>>>>> 54350c2788c098abd28af1b50af1695d30af1197
void free_list(list_t **head_ptr)
{
list_t *current_node, *next_node, *head;

if (!head_ptr || !*head_ptr)
return;

head = *head_ptr;
current_node = head;
while (current_node)
{
next_node = current_node->next;
free(current_node->str);
free(current_node);
current_node = next_node;
}

*head_ptr = NULL;
}
