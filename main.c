#include "shellme.h"

/**
* main - Entry point
* @ac: ac
* @arg: array
* Return: 0
*/

int main(int ac __attribute__((unused)), char **arg  __attribute__((unused)))
{
char **args = NULL;
char *input_s = NULL;
int ac_s = 1;
int exit_s = 0;


ssize_t nil = 0;
size_t si_se = 0;

while (ac_s && nil != EOF)
{
si_se = 0;
ac_s = isatty(STDIN_FILENO);

if (ac_s)
write(STDOUT_FILENO, "", 0);

signal(SIGINT, signal_handler);
nil = getline(&input_s, &si_se, stdin);
if (nil == -1)
{
free(input_s);
break;
}
if (space_validation(input_s))
{
free(input_s);
continue;
}
args = _tonken(input_s);
if (*args[0] == '\0')
continue;
ac_s = _exe(args, input_s, arg, &exit_s);
free(input_s);
free(args);
}

return (0);
}
