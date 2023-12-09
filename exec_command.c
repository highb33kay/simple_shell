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

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}

	path = get_path(tokens[0]);

	if (child_pid == 0)
	{

		printf("Child %d executing command: %s\n", getpid(), tokens[0]);

		execvp(path, tokens);

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

	free(path);

	return (-1);
}
