#define _POSIX_C_SOURCE 200809L

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * get_path - Get path of the token
 * @token: Pointer to the token
 * Return: Pointer to the path
 */
char *get_path(char *token)
{
	char *path_token;

	char *original_path = getenv("PATH");

	char *path = (char *)malloc(strlen(original_path) + 1);

	if (path == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	strcpy(path, original_path);

	path_token = strtok(path, ":");

	while (path_token != NULL)
	{
		char *full_path = (char *)malloc(strlen(path_token) + strlen(token) + 2);

		if (full_path == NULL)
		{
			perror("Failed to allocate memory");
			exit(EXIT_FAILURE);
		}

		strcpy(full_path, "/usr/bin");
		strcat(full_path, "/");
		strcat(full_path, token);

		printf("full_path: %s\n", full_path);

		free(path);
		printf("here is the full_path: %s\n", full_path);
		return (full_path);

		free(full_path);
		path_token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
