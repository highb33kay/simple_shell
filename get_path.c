#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

char *get_path(char *token)
{
	char *path = NULL;
	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: $PATH environment variable not found\n");
		exit(EXIT_FAILURE);
	}

	char *path_env_copy = strdup(path_env);
	if (path_env_copy == NULL)
	{
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}

	char *dir = strtok(path_env_copy, ":");

	printf("Searching for %s in %s\n", token, dir);

	char fullPath[MAX_PATH_LENGTH];

	while (dir != NULL)
	{
		if (strcmp(dir, token) == 0)
		{
			// If dir and token are the same, set fullPath to dir
			snprintf(fullPath, sizeof(fullPath), "%s", dir);
		}
		else
		{
			// Otherwise, construct the full path as usual
			snprintf(fullPath, sizeof(fullPath), "%s/%s", dir, token);
		}

		// Check if the command exists at the current path
		if (access(fullPath, F_OK) == 0)
		{
			// Allocate memory for the full path and copy the result
			char *resultPath = malloc(strlen(fullPath) + 1);
			if (resultPath == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(resultPath, fullPath);

			// Free the memory used for the path copy
			free(path_env_copy);

			return resultPath;
		}

		// Get the next directory in the PATH
		dir = strtok(NULL, ":");
	}

	free(path_env_copy);

	return (path);
}
