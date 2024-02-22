#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <signal.h>

extern char **environ;

char **split_string(const char *str, const char *delimiters,
					size_t *num_words);
char *prompt(void);
void perror_mem_alloc(void);
char *trim_newline(char *str);
void free_list(char **list);
char **word_list(char *str, char *delim);
void handle_exit(int signum __attribute__((unused)));
void print_environment();

#endif
