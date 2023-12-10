#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	char **tokens = NULL;

	write(STDOUT_FILENO, "Welcome User\n", 14);

	while (1)
	{

		line = get_command();

		tokens = tokenize_command(line);

		if (strcmp(tokens[0], "exit") == 0)
		{
			write(STDOUT_FILENO, "😘", 5);
			exit(EXIT_SUCCESS);
		}

		execute_command(tokens);

		free(tokens);

		free(line);
	}

	return (-1);
}
