#include "shell.h"

/**
 * get_environ - str array copy of environ
 * @info: structure with potential arguments used to maintain
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
 * _unsetenv - environment variable remove
 * @info: structure with potential arguments used to maintain
 *        the constant function prototype.
 *  Return:  0 or 1 on delete
 * @var: str env var
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *nodee = info->env;
	size_t m = 0;
	char *c;

	if (!nodee || !var)
		return (0);

	while (nodee)
	{
		c = starts_with(nodee->str, var);
		if (c && *c == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), m);
			m = 0;
			nodee = info->env;
			continue;
		}
		nodee = nodee->next;
		m++;
	}
	return (info->env_changed);
}

/**
 * _setenv - new environment  init variable
 *             or modify an existing one
 * @info: structure wiith potential arguments used to maintain
 *        the constant function prototype.
 * @var:  property of str env var
 * @value:  value string env var
 *  Return: 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *nodee;
	char *c;

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
		c = starts_with(nodee->str, var);
		if (c && *c == '=')
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
