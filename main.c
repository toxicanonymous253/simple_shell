#include "shell.h"

/**
 * main - checks all the code
 * Return: 0 always when success
 */
int main(void)
{
	char *user_input, *args[32], *command, *command_copy, *directory, full_path[100];
	int status,arg_count = 0;
	pid_t child_pid;
	command = getenv("PATH");
	command_copy = strdup(command);
	user_input = (char *)malloc(100 * sizeof(char));
	if (user_input == NULL)
	{
		perror("malloc");
		exit(1);
	}

	while (1)
	{
		printf("#cisfun$ ");/*Displays a prompt*/
		fgets(user_input, sizeof(user_input), stdin);/*reading thse users input*/

		user_input[strcspn(user_input, "\n")] = '\0';/*removing the new line*/
		command = strtok(user_input, " ");

		if (command == NULL)
			continue;
		if (strcmp(command, "exit") == 0)
		{
			free(user_input);
			break;
		}
		directory = strtok(command_copy, ":");
		while (directory != NULL)
		{
			sprintf(full_path, "%s/%s", directory, command);
			if (fileExists(full_path))/*Checkin if executable exists*/
			{
				child_pid = fork();
				
				if (child_pid == -1)
				{
					perror("fork");
					exit(1);
				}
				if (child_pid == 0)
				{
					args[arg_count] = command;
					while ((args[arg_count] = strtok(NULL, " ")) != NULL)
						arg_count++;
					execve(full_path, args, environ);
					perror("execve");
					exit(1);
				}
				else
					wait(&status);
			}
			directory = strtok(NULL, ":");
		}
	}
	free(command_copy);
	return (0);
}
