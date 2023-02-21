#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define TOK_DELIM " \t\r\n"
#define RED "\033[0;31m"
#define RESET "\e[0m"

extern char **environ;

int _putchar(char c);
void print_prompt(void);
char **split_line(char *line);
int shell_exit(void);
void loop(void);
int execute(char **args);
int _strcmp(char *s1, char *s2);
int my_execvp(char *name, char **argv);
char *_strstr(register char *string, char *substring);
char *_strcat(char *dest, char *src);
void *_realloc(void * ptr, size_t old_size, size_t new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
