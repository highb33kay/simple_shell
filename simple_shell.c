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

	while (1)
	{
		printf("Hello User 😃 \n");
		line = get_command();

		tokens = tokenize_command(line);

		if (strcmp(tokens[0], "exit") == 0)
		{
			printf("Goodbye! 😢\n");
			exit(EXIT_SUCCESS);
		}

		execute_command(tokens);

		free(tokens);

		free(line);
	}

	return (-1);
}
