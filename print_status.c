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
		write(STDOUT_FILENO, "😊: Child process terminated normally\n", 41);
	else
		write(STDOUT_FILENO, "😭: Child process terminated abnormally\n", 43);
}
