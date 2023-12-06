#define _POSIX_C_SOURCE 200809L

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_command - Get command from the user
 * @command: Pointer to the command entered by the user
 *
 * Return: Nothing
 */
char get_command(char **command)
{
	size_t bufsize = 0;
	int characters = 0;

	printf("$ ");
	characters = getline(command, &bufsize, stdin);

	if (characters == -1)
	{
		free(*command);
		perror("Failed to read the command");
		exit(EXIT_FAILURE);
	}

	if (characters == EOF)
	{
		free(*command);
		write(STDOUT_FILENO, " Done with the program\n ", 1);
		exit(EXIT_SUCCESS);
	}

	write(STDOUT_FILENO, *command, characters);

	return (characters);
}
