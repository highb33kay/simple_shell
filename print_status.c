#include "shell.h"

/**
 * wait_and_print_status - Wait for a child process to terminate
 * @child_pid: PID of the child process
 * Return: Nothing
 */
void wait_and_print_status(pid_t child_pid)
{
	int status;

	waitpid(child_pid, &status, 0);

	if (WIFEXITED(status))
		printf("Child %d with exit status=%d\n", child_pid, WEXITSTATUS(status));
	else
		printf("Child %d terminated abnormally\n", child_pid);
}
