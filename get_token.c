#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * tokenize_command - Tokenize command
 * @command: Pointer to the command entered by the user
 * @delim: Delimiter
 * Return: Pointer to the array of tokens
 */
char **tokenize_command(char *command, char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
