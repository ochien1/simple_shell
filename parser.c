#include "shell.h"

/**
* is_executable - checks whether a file is executable
* @information: info struct
* @filePath: string representing file path
*
* Return: 1 if true, 0 otherwise
*/
int is_executable(info_t *information, char *filePath)
{
struct stat st;

(void)information;
if (!filePath || stat(filePath, &st))
return (0);

if (st.st_mode & S_IFREG && st.st_mode & S_IXUSR)
{
return (1);
}
return (0);
}

/**
* copy_chars - makes a copy of characters from start to stop
* @source: source string
* @start: the source index
* @stop: the destination index
*
* Return: pointer to new buffer
*/
char *copy_chars(char *source, int start, int stop)
{
static char buffer[1024];
int index = 0, k = 0;

for (k = 0, index = start; index < stop; index++)
if (source[index] != ':')
buffer[k++] = source[index];
buffer[k] = 0;
return (buffer);
}

/**
* find_full_path - searches for the full path of command
* @information: info struct pointer
* @pathString: string representing PATH env variable
* @command: the command to find
*
* Return: full path of command if found or NULL
*/
char *find_full_path(info_t *information, char *pathString, char *command)
{
int index = 0, curr_pos = 0;
char *fullPath;

if (!pathString)
return (NULL);

if ((_strlen(command) > 2) && starts_with(command, "./"))
{
if (is_executable(information, command))
return (command);
}

while (1)
{
if (!pathString[index] || pathString[index] == ':')
{
fullPath = copy_chars(pathString, curr_pos, index);
if (!*fullPath)
_strcat(fullPath, command);
else
{
_strcat(fullPath, "/");
_strcat(fullPath, command);
}
if (is_executable(information, fullPath))
return (fullPath);
if (!pathString[index])
break;
curr_pos = index;
}
index++;
}
return (NULL);
}
