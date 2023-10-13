#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: the Structure containing potential arguments. Used to maintain
 *          a constant function prototype.
 * Return:  0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - geting the value of an environ variable
 * @info: the Structure containing potential arguments. Used to maintain
 * @name:  env var name
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *k;

	while (node)
	{
		k = starts_with(node->str, name);
		if (k && *k)
			return (k);
		node = node->next;
	}
	return (0);
}

/**
 * _mysetenv - the Initialize a new environment variable,
 *             or modify an existing one
 * @info: the Structure containing potential arguments. Used to maintain
 *        a constant function prototype.
 *  Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: the Structure containing potential arguments. Used to maintain
 *        the constant function prototype.
 *  Return: 0
 */
int _myunsetenv(info_t *info)
{
	int r;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (r = 1; r <= info->argc; r++)
		_unsetenv(info, info->argv[r]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: the Structure containing potential arguments. Used to maintain
 *           the constant function prototype.
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t r;

	for (r = 0; environ[r]; r++)
		add_node_end(&node, environ[r], 0);
	info->env = node;
	return (0);
}
