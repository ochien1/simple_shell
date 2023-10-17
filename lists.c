#include "shell.h"

/**
* add_node - adds a node to the start of the list
* @head: the address of pointer to head node
* @str_value: a string value for the node
* @node_index: the node index used by history
*
* Return: the new node
*/
list_t *add_node(list_t **head, const char *str_value, int node_index)
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
