#include "shellme.h"

/**
* _cd - The current working directory
* @av: array
* @input:input
* @exiti:exit
* Return: 1 true
*/
int _cd(char **av, char *input, int *exiti)
{
	int stat;

	char str[128];

	(void)input;
	(void)exiti;

	if (av[1] == NULL)
		stat = chdir(get_en("HOME"));
	else if (strcmp(av[1], "-") == 0)
		stat = chdir(get_en("OLDPWD"));
	else if (strcmp(av[1], "~") == 0)
		stat = chdir(get_en("HOME"));
	else
		stat  = chdir(av[1]);

	if (stat == -1)
		perror("There is an error in the cd");

	setenv("OLDPWD", str, 1);
	setenv("PWD", getcwd(str, sizeof(str)), 1);
	return (1);
}
