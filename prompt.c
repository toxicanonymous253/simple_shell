#include "shell.h"

/**
 * prompt - this function will allow the user to input command
 * @argv: this is the command entered
 * Return: 0 when successfull
 */

extern char **environ;
int prompt(char *agrv[MAX_COMMAND_LENGTH])
{
	int status;
	/*When true always run this command*/
	while (1)
	{
		/*Display the prompt*/
		printf("$ ");

		fgets();
	}
}