#include "shell.h"

/**
 * execute_command - Execute the command
 * @tokens: Tokens of the command
 * Return: Nothing
 */
int execute_command(char **tokens)
{
	pid_t child_pid;
	char *path = get_path(tokens[0]);

	if (path == NULL)
	{
		print_tokens(tokens);
		return (-1);
	}
	else
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			execute_child(path, tokens);
		}
		else
		{
			wait_and_print_status(child_pid);
		}
	}

	return (-1);
}
