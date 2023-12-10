#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_PATH_LENGTH 1024
#define TOK_DELIM " \t\r\n\a"
#define _POSIX_C_SOURCE 200809L
#define MAX_INPUT_SIZE 1024

/* Function prototypes */
/* get command from the user*/
char *get_command(void);
/* tokenize command */
char **tokenize_command(char *line);
/* execute command */
int execute_command(char **tokens);
/* get path of the token */
char *get_path(char *token);

char *_strdup(const char *str);

void execute_child(char *path, char **tokens);
void wait_and_print_status(pid_t child_pid);
void print_tokens(char **tokens);
char *get_path_env();
char *construct_full_path(const char *dir, const char *token);
int _file_exists(const char *file_path);
#endif
