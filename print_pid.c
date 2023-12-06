#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_pid - Prints the PID of the current shell process
 * @void: No arguments passed
 *
 * Return: PID of the parent process
 */
int print_pid(void)
{
	int pid;
	int ppid;
	int cpid;
	int pcpid;
	int id2 = 0;
	int id = 0;

	id = fork();

	if (id == 0)
	{
		pid = getpid();
		printf("PID: %d\n", pid);

		id2 = fork();

		if (id2 == 0)
		{
			cpid = getpid();
			printf("CPID: %d\n", cpid);
		}
		else
		{
			pcpid = getppid();
			printf("PCPID: %d\n", pcpid);
		}
	}
	else
	{
		ppid = getppid();
		printf("PPID: %d\n", ppid);
	}

	printf("End of everything\n");

	return (0);
}

/**
 * main - Entry point
 * @argc: Number of arguments passed
 * @argv: Array of arguments passed
 *
 * Return: Always 0
 */
int main(void)
{
	print_pid();
	return (0);
}