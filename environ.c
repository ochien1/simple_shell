#include "shell.h"

/**
 * _myenv - print current env.
 * @info: struct with potential arguments. Used to maintain
 *          a constant function prototype.
 * Return:  0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - env variable value
 * @info: struct with potential arguments used to maintain
 * @name:  env var name
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *b;

	while (node)
	{
		b = starts_with(node->str, name);
		if (b && *b)
			return (b);
		node = node->next;
	}
	return (0);
}

/**
 * _mysetenv - new env variable initializer,
 *             or modify existing
 * @info: struct with potential arguments used to maintain
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
 * _myunsetenv - Remove an env var
 * @info: struct with potential arguments used to maintain
 *        a constant function prototype.
 *  Return: 0
 */
int _myunsetenv(info_t *info)
{
	int m;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (m = 1; m <= info->argc; m++)
		_unsetenv(info, info->argv[m]);

	return (0);
}

/**
 * populate_env_list - linked listenv
 * @info: struct with potential arguments used to maintain
 *           the constant function prototype.
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t m;

	for (m = 0; environ[m]; m++)
		add_node_end(&node, environ[m], 0);
	info->env = node;
	return (0);
}
