#define _POSIX_C_SOURCE 200809L

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024
/**
 * get_command - Get command from the user
 * @command: Pointer to the command entered by the user
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
