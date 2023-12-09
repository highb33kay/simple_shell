#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *command = NULL;
	char **tokens = NULL;

	while (1)
	{
		get_command(&command);

		tokens = tokenize_command(command, " ");

		// Process or use 'tokens' as needed
		// For example, print the tokens
		int i = 0;
		while (tokens[i] != NULL)
		{
			printf("Token %d: %s\n", i, tokens[i]);
			i++;
		}

		execute_command(tokens);

		// Free allocated memory for tokens
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);

		free(tokens);

		// free command
		free(command);

		// check if command is built-in
		// execute built-in command
		// exit
		// check if command is executable
		// fork
		// child
		// parent
		// execve
		// check if command is found
		// execute command
		// check if command is not found
		// print error message
		// wait
		// check if child process terminated normally
		// print error message
		// check if child process terminated abnormally
		// print error message
		// free command
	}

	return (-1);
}
