// get_path.c

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
	char *original_path = getenv("PATH");

	printf("original_path: %s\n", original_path);

	char *path = (char *)malloc(strlen(original_path) + 1);

	if (path == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	strcpy(path, original_path);

	char *path_token = strtok(path, ":");

	printf("path_token: %s\n", path_token);

	// find the full path of the token

	while (path_token != NULL)
	{
		char *full_path = malloc(strlen(path_token) + strlen(token) + 2);
		printf("full_path: %s\n", full_path);

		if (full_path == NULL)
		{
			perror("Failed to allocate memory");
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s/%s", path_token, token);

		free(path);
		printf("full_path: %s\n", full_path);
		return (full_path);

		free(full_path);
		path_token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
