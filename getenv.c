#include "shell.h"

/**
 * get_environ - returning the string array copy of our environ
 * @info: the Structure containing potential arguments. Used to maintain
 *          the constant function prototype.
 * Return: 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: the Structure containing potential arguments. Used to maintain
 *        the constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *nodee = info->env;
	size_t k = 0;
	char *p;

	if (!nodee || !var)
		return (0);

	while (nodee)
	{
		p = starts_with(nodee->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), k);
			k = 0;
			nodee = info->env;
			continue;
		}
		nodee = nodee->next;
		k++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: the Structure containing potential arguments. Used to maintain
 *        the constant function prototype.
 * @var:  string env var property
 * @value:  string env var value
 *  Return: 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *nodee;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	nodee = info->env;
	while (nodee)
	{
		p = starts_with(nodee->str, var);
		if (p && *p == '=')
		{
			free(nodee->str);
			nodee->str = buf;
			info->env_changed = 1;
			return (0);
		}
		nodee = nodee->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
