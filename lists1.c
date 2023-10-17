#include "shell.h"

/**
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
}

strings[len] = NULL;
return (strings);
}

/**
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
}
