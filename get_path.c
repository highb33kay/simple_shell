#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

char *get_path(char *token)
{
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

	while (dir != NULL)
	{
		char fullPath[MAX_PATH_LENGTH];

		if (strncmp(token, "/bin/", 5) == 0)
		{
			snprintf(fullPath, sizeof(fullPath), "%s", token);
		}
		else
		{
			snprintf(fullPath, sizeof(fullPath), "%s/%s", dir, token);
		}

		if (access(fullPath, F_OK) == 0)
		{
			char *resultPath = strdup(fullPath);

			if (resultPath == NULL)
			{
				perror("strdup failed");
				exit(EXIT_FAILURE);
			}

			free(path_env_copy);
			return resultPath;
		}

		dir = strtok(NULL, ":");
	}

	free(path_env_copy);

	return NULL;
}
