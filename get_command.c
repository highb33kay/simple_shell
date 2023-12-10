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

	printf("😒😭 ");
	getline(&line, &bufsize, stdin);

	return (line);
}
