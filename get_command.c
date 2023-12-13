#include "shell.h"

/**
 * get_command - Get command from the user
 *
 * Return: Nothing
 */
char *get_command(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	write(STDOUT_FILENO, "($) ", 5);
	getline(&line, &bufsize, stdin);

	return (line);
}
