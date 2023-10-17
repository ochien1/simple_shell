#include "shell.h"

/**
 * _myhistory - history list display,1 command by line, preceded
 *              starting at 0 with line numbers
 * @info: struct with potential arguments. Used to maintain
 *        a constant function prototype.
 *  Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - string setter
 * @info: struct par
 * @str: alias str
 *
 * Return: Always  1 on error,0 on success
 */
int unset_alias(info_t *info, char *str)
{
	char *b, q;
	int ret;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	q = *b;
	*b = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*b = q;
	return (ret);
}

/**
 * set_alias - string alias setter
 * @info: parameter str
 * @str: alias str
 *
 * Return: Always  1 on error 0 on success
 */
int set_alias(info_t *info, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - string alias printer
 * @node: node alias
 *
 * Return: Always 1 on error 0 on success
 */
int print_alias(list_t *node)
{
	char *b = NULL, *g = NULL;

	if (node)
	{
		b = _strchr(node->str, '=');
		for (g = node->str; g <= b; g++)
			_putchar(*g);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - man alias
 * @info: struct with potential arguments. Used to maintain
 *          a constant function prototype.
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *b = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		b = _strchr(info->argv[x], '=');
		if (b)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}
