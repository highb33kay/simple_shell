#include "shell.h"

/**
 * print_tokens - Print tokens
 * @tokens: Pointer to the array of tokens
 * Return: Nothing
 */
void print_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		write(STDOUT_FILENO, tokens[i], strlen(tokens[i]));
		write(STDOUT_FILENO, " ", 1);
	}
	write(STDOUT_FILENO, "\n", 1);
}
