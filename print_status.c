#include "shell.h"

/**
 * wait_and_print_status - Wait for a child process to terminate
 * @child_pid: PID of the child process
 * Return: Nothing
 */
int wait_and_print_status(pid_t child_pid)
{
	int status;

	waitpid(child_pid, &status, 0);

	if (WIFEXITED(status))
		return (0);
	else
		return (1);
}
