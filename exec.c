#include "shellme.h"

/**
 * _exe - for built commands
 * @a: args
 * @input_s:input
 * @args: argv
 * @exit_s: exit
 *
 * Return: e work
 */
int _exe(char **a, char *input_s, char **args, int *exit_s)
{
int i;

choice_t choices[] = {
{"exit", p_exit},
{"en", _en},
{"cd", _cd},
{"setenv", h_setenv},
{"unsetenv", h_unsetenv},
{NULL, NULL}
};

i = 0;

while (choices[i].naming_built)
{
if (strcmp(choices[i].naming_built, a[0]) == 0)

return ((int)((*choices[i].fun_built)(a, input_s, exit_s)));

i++;
}

return (_exe_p(a, args, exit_s));
}
