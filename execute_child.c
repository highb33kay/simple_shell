#include "shell.h"

/**
 * execute_child - Execute the command in the child process
 * @path: Path of the command
 * @tokens: Tokens of the command
 * Return: Nothing
 */
void execute_child(char *path, char **tokens)
{
	char *error_message;

	tokens[0] = path;

	error_message = _strdup("./shell: No such file or directory\n ");
	if (execve(tokens[0], tokens, NULL) == -1)
	{
		write(STDERR_FILENO, error_message, strlen(error_message));
		free(error_message);
		_exit(EXIT_FAILURE);
	}
	write(STDERR_FILENO, error_message, strlen(error_message));
	perror(tokens[0]);
	exit(EXIT_FAILURE);
}
