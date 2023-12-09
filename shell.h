#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Function prototypes */
/* get command from the user*/
char *get_command(void);
/* tokenize command */
char **tokenize_command(char *line);
/* execute command */
int execute_command(char **tokens);
/* get path of the token */
char *get_path(char *token);

#endif
