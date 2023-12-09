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
	int i = 0;

	while (1)
	{
		get_command(&command);

		tokens = tokenize_command(command, " ");

		while (tokens[i] != NULL)
		{
			printf("Token %d: %s\n", i, tokens[i]);
			i++;
		}

		execute_command(tokens);

		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);

		free(tokens);

		free(command);
	}

	return (-1);
}
