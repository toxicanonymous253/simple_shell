#include "shellme.h"

/**
* _exe_p - Executes the commands
* @agu: agu
* @arg: arg
* @exiti: exit
* Return: 1
*/
int _exe_p(char **agu, char **arg, int *exiti)
{
pid_t pid;
char *n_agu;
int ac_s;

n_agu = input_validation(agu, arg);
if (strcmp(n_agu, "Fail access") == 0)
return (1);

pid = fork();
if (pid == 0)
{
if (execve(n_agu, arg, environ) == -1)
{
perror("Error ");
exit(EXIT_FAILURE);
}
}

else if (pid < 0)
{
perror("Error ");
free(n_agu);
return (1);
}

else
{
waitpid(-1, &ac_s, 0);
if (WEXITSTATUS(ac_s))
*exiti = WEXITSTATUS(ac_s);
if (agu[0][0] != '/' && agu[0][0] != '.')
free(n_agu);
return (1);
}

return (1);
}
