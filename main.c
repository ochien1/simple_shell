#include "shell.h"

/**
<<<<<<< HEAD
* main - the entry point
* @argc: argument count
* @argv: argument vector
*
* Return: 0 on success, 1 on error
*/
int main(int argc, char **argv)
=======
 * main - entry point
 * @ac: count of argument
 * @av: vector of argument
 *
 * Return:  1 on error 0 on success
 */
int main(int ac, char **av)
>>>>>>> 54350c2788c098abd28af1b50af1695d30af1197
{
info_t info[] = { INFO_INIT };
int file_descriptor = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (file_descriptor)
: "r" (file_descriptor));

if (argc == 2)
{
file_descriptor = open(argv[1], O_RDONLY);
if (file_descriptor == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(argv[0]);
_eputs(": 0: Can't open ");
_eputs(argv[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = file_descriptor;
}
populate_env_list(info);
read_history(info);
hsh(info, argv);
return (EXIT_SUCCESS);
}
