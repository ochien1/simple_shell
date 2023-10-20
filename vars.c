#include "shell.h"

/**
 * is_chain - validates char in buffer is  chain
 * @info: struct para
 * @buffer: buffer
 * @pos: address in buffer
 *
 * Return: 0 or 1 if chain delimiter
 */
int is_chain(info_t *info, char *buffer, size_t *pos)
{
	size_t w = *pos;

	if (buffer[w] == '|' && buffer[w + 1] == '|')
	{
		buffer[w] = 0;
		w++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buffer[w] == '&' && buffer[w + 1] == '&')
	{
		buffer[w] = 0;
		w++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buffer[w] == ';')
	{
		buffer[w] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*pos = w;
	return (1);
}

/**
 * check_chain - if chain should continue
 * @info: struct para
 * @buffer: buffer char
 * @pos: add in buffer
 * @start: starting position
 * @length: length buffer
 *
 * Return: Zero
 */
void check_chain(info_t *info, char *buffer, size_t *pos,
		size_t start, size_t length)
{
	size_t w = *pos;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buffer[start] = 0;
			w = length;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buffer[start] = 0;
			w = length;
		}
	}

	*pos = w;
}

/**
 * replace_alias - incognito restorer to tokenised
 * @info: str parameter
 * Return: 0 or 1 if replaced
 */
int replace_alias(info_t *info)
{
	int z;
	list_t *node;
	char *p;

	for (z = 0; z < 10; z++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - variables in tokenised str
 * @info: struct para
 *
 * Return: 0 or 1 if replaced
 */
int replace_vars(info_t *info)
{
	int z = 0;
	list_t *node;

	for (z = 0; info->argv[z]; z++)
	{
		if (info->argv[z][0] != '$' || !info->argv[z][1])
			continue;

		if (!_strcmp(info->argv[z], "$?"))
		{
			replace_string(&(info->argv[z]),
						   _strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[z], "$$"))
		{
			replace_string(&(info->argv[z]),
						   _strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[z][1], '=');
		if (node)
		{
			replace_string(&(info->argv[z]),
						   _strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[z], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - string restore
 * @old: starring source
 * @new: string desttination
 *
 * Return: 0 or 1 if replaced
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
