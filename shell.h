#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Function prototypes */
/* get command from the user*/
char get_command(char **command);
/* tokenize command */
char **tokenize_command(char *command, char *delim);
#endif
