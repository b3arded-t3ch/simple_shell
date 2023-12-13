#ifndef main_H
#define main_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
extern char **environ;
char **tokenize(char *str, const char *delim);
void pro_exec(char **commands);
void free_commands(char **command);
void get_pathname(char **command);
void exit_func(char **tok_ret);
char *get_input();
#endif
