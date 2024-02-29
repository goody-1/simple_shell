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

/* core functions */
char **split_string(const char *str, const char *delimiters,
					size_t *num_words);
char **word_list(char *str, char *delim);
void handle_exec(char **list, char *str, int ppid);

/*** HELPER FUNCTIONS ***/
/*==================================*/
/* defined in string_functions */
size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);

/* defined in mem_functions */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_memmove(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* defined in main */
void print_environment(void);

/* defined in split_str */
void perror_handler(char *error);
char *trim_newline(char *str);

/* defined in utilities */
void free_list(char **list);
void handle_kill(int signum __attribute__((unused)));
void handle_exit(char **list, char *str, int ppid,
					int exit_status, char *p_err, int terminate);

/* defined in prompt */
char *prompt(void);
char *read_line(FILE *input);

#endif /* MAIN_H */
