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
	char *line;
	char **tokens = NULL;
	int i = 0;

	while (1)
	{
		line = get_command();

		tokens = tokenize_command(line);

		while (tokens[i] != NULL)
		{
			printf("Token %d: %s\n", i, tokens[i]);
			i++;
		}

		execute_command(tokens);

		free(tokens);

		free(line);
	}

	return (-1);
}
