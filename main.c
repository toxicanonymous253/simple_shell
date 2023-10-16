#include "shell.h"

/**
 * main - checks all the code
 * Return: 0 always when success
 */
int main(void)
{
	char command[100];
	char *argv[] = {NULL, NULL};
	int status;
	pid_t child_pid;

	while (1)
	{
		printf("#cisfun$ ");/*Displays a prompt*/
		fgets(command, sizeof(command), stdin);/*reading thse users input*/

		command[strcspn(command, "\n")] = '\0';/*removing the new line*/

		if (strcmp(command, "exit") == 0)
			break;
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			exit(1);
		}
		if (child_pid == 0)
		{
			execve(command, argv, environ);
			perror("./shell");/*if execve fails*/
			exit(1);
		}
		else
			wait(&status);
	}
	return (0);
}
