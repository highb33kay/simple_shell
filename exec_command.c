#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Entry point
 * @tokens: tokens to execute
 *
 * Return: Always 0
 */
int execute_command(char **tokens)
{
	pid_t child_pid;
	char *path = NULL;
	char *error_message;

	path = get_path(tokens[0]);

	if (path == NULL)
	{
		write(STDOUT_FILENO, *tokens, strlen(*tokens));
		write(STDOUT_FILENO, "\n", 1);
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

			tokens[0] = path;

			error_message = _strdup("😒😭: Could not execute command\n ");

			if (execve(tokens[0], tokens, NULL) == -1)
			{

				// Print the command if execve fails
				write(STDERR_FILENO, error_message, strlen(error_message));
				free(error_message);
				_exit(EXIT_FAILURE);
			}
			fprintf(stderr, "Error: execve failed\n");
			perror(tokens[0]);
			exit(EXIT_FAILURE);
		}
		else
		{

			int status;

			waitpid(child_pid, &status, 0);

			if (WIFEXITED(status))
				printf("Child %d terminated normally with exit status=%d\n", child_pid, WEXITSTATUS(status));
			else
				printf("Child %d terminated abnormally\n", child_pid);
		}
	}

	return (-1);
}
