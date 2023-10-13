#include "shell.h"

/**
 * main - checks all the code
 * Return: 0 always when success 
 */

int main(void)
{
	char buffer[100], *args, *token;
	pid_t child_pid;
	int i = 0;

	while (1)
	{
		/*Display a prompt*/
		printf("$ ");

		/*read command inputed*/
		fgets(buffer, sizeof(buffer), stdin);

		token = strtok(buffer, "\n");

		while(token != NULL)
		{
			args[i] = token;/*assigning the tokenized commands*/
			token = strtok(NULL, "\n");
			i++;
		}
	}

	return (0);
}
