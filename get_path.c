#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

char *get_path(char *token)
{
	char *path = NULL;
	char *path_env_copy;
	char *dir;
	char fullPath[MAX_PATH_LENGTH];
	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: $PATH environment variable not found\n");
		exit(EXIT_FAILURE);
	}

	path_env_copy = strdup(path_env);
	if (path_env_copy == NULL)
	{
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}

	dir = strtok(path_env_copy, ":");

	printf("Searching for %s in %s\n", token, dir);

	while (dir != NULL)
	{
		if (strcmp(dir, token) == 0)
		{
			snprintf(fullPath, sizeof(fullPath), "%s", dir);
		}
		else
		{
			snprintf(fullPath, sizeof(fullPath), "%s/%s", dir, token);
		}

		if (access(fullPath, F_OK) == 0)
		{
			char *resultPath = malloc(strlen(fullPath) + 1);
			if (resultPath == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(resultPath, fullPath);

			free(path_env_copy);

			return resultPath;
		}

		dir = strtok(NULL, ":");
	}

	free(path_env_copy);

	return (path);
}
