#include "shell.h"

/**
 * main - checks all the code
 * Return: 0 always when success
 */
int main(void)
{
	char buffer[100];
	pid_t child_pid;
	while (1)
	{
		/*Display a prompt*/
		printf("#cisfun$ ");
		fgets(buffer, sizeof(buffer), stdin);/*Read the input and store it in buffer*/
		buffer[strcspn(buffer, "\n")] = '\0';/*Removing the \n from the command*/
		child_pid = fork();/*starting child process*/
		if (child_pid == -1)/*failed child process*/
		{
			perror("Error:");
			exit(1);
		}
		if (child_pid == 0)/*successfull child process*/
		{
			char *args[] = {buffer, NULL};
			execve();
		}
	}
	return (0);
}
