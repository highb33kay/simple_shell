#include "shell.h"

/**
 * construct_full_path - Construct the full path for a given token
 * @dir: Directory
 * @token: Token
 *
 * Return: The full path
 */
char *construct_full_path(const char *dir, const char *token)
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

	return (_strdup(fullPath));
}
