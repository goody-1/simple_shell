#include "main.h"

/**
 * main - starting point for programme execution
 * @list: a pointer pointing to a list
 * @num_words: number of words to be counted in a string
 * @str: input str
 *
 * Return: always success
 */


int main(void)
{
	char *str, **list;
	size_t num_words;
	pid_t ppid = getpid();
	FILE *input_file = stdin;

	if (isatty(STDIN_FILENO)) /* check if program is running interactively */
	{
		while (1)
		{
			str = prompt();
			list = split_string(str, " \t\n", &num_words);
			list[num_words] = NULL;

			handle_exec(list, str, ppid);
			if (list)
				free_list(list);
			if (str)
				free(str);
		}
	}
	else
	{ /* program is running in non-interactive mode */
		while ((str = read_line(input_file)) != NULL)
		{
			list = split_string(str, " \t\n", &num_words);
			list[num_words] = NULL;

			handle_exec(list, str, ppid);

			if (list)
				free_list(list);
			if (str)
				free(str);
		}
	}
	return (0);
}

/**
 * handle_exec - this is a function that executes the prompt
 */
void handle_exec(char **list, char *str, int ppid)
{
	int status, no_kill = 0, terminate = 1;
	pid_t child = fork();

	if (child == -1)
		handle_exit(list, str, ppid, EXIT_FAILURE, "fork", terminate);

	if (child == 0)
	{
		 /* case where input to getline function is -1: CTRL + D */
		if (!list || !list[0])
			handle_exit(list, NULL, ppid, EXIT_SUCCESS, NULL, terminate);

		if (_strcmp(list[0], "exit") == 0)
			handle_exit(list, str, ppid, EXIT_SUCCESS, NULL, terminate);

		if (_strcmp(list[0], "env") == 0 || _strcmp(list[0], "printenv") == 0)
		{
			print_environment();
			handle_exit(list, str, ppid, EXIT_SUCCESS, NULL, no_kill);
		}

		/* handle commands */
		if (execve(list[0], list, environ) == -1)
			handle_exit(list, str, ppid, EXIT_FAILURE, "./shell", no_kill);
	}

	wait(&status); /* wait for child process to finish */
}

/**
 * print_environment - 
void print_environment(void)
{
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
}
