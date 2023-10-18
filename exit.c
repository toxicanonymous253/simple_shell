#include "shellme.h"

/**
* p_exit - Exit command
* @av: array
* @input:input
* @exiti:exit
* Return: true
*/
int p_exit(char **av, char *input, int *exiti)
{
int exit_show;
exit_show = 0;

(void)av;
(void)input;
(void)exit;

if (av[1] == NULL)
{
free(av);
free(input);
exit(*exiti);
}

if (av[1] == NULL)
{
fprintf(stderr, "exit: There are many arguments in here\n");
return (0);
}

exit_show = atoi(av[1]);
free(av);
free(input);
exit(exit_show);
}
