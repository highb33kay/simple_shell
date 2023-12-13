#include "shell.h"

/**
 * get_path_env - Get the $PATH environment variable
 * Return: The $PATH environment variable
 */
char *get_path_env()
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		write(STDERR_FILENO, "./shell: No such file or directory\n", 36);
		exit(EXIT_FAILURE);
	}

	return (_strdup(path_env));
}
