#include "shell.h"

/**
 * get_path - Get the full path for a given token
 * @token: Token
 * Return: The full path if the file exists, NULL otherwise
 */
char *get_path(char *token)
{
	char *path_env_copy = get_path_env();
	char *dir = strtok(path_env_copy, ":");

	while (dir != NULL)
	{
		char *fullPath = construct_full_path(dir, token);

		if (_file_exists(fullPath))
		{
			free(path_env_copy);
			return (fullPath);
		}

		free(fullPath);
		dir = strtok(NULL, ":");
	}

	free(path_env_copy);
	return (NULL);
}
