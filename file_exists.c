#include "shell.h"

/**
 * _file_exists - Check if a file exists
 * @file_path: Path to the file
 * Return: 1 if the file exists, 0 otherwise
 */
int _file_exists(const char *file_path)
{
	return (access(file_path, F_OK) == 0);
}
