#include "main.h"

int exit_code = EXIT_SUCCESS;
/**
 * main - entry to program
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
 * handle_exec - handle core execution of shell
 *
 * @list: list of words / argument passed to the shell
 * @str: the string passed
 * @ppid: the pid of the core process
 *
 * Return: void
*/
void handle_exec(char **list, char *str, int ppid)
{
	int status, no_kill = 0, terminate = 1;
	char *prefix = "/bin/";
	pid_t child;

	if (list && list[0] && (_strcmp(list[0], "exit") != 0) &&
		(_strncmp(list[0], prefix, 5) != 0))
	{
		size_t old_len = _strlen(list[0]);
		size_t new_len = _strlen(prefix) + old_len + 1;

		list[0] = _realloc(list[0], old_len, new_len);
		if (!list[0])
			return;
		_memmove(list[0] + _strlen(prefix), list[0], old_len);
		_memcpy(list[0], prefix, _strlen(prefix));
		list[0][new_len - 1] = '\0';
	}
	if (list && list[0] && (_strcmp(list[0], "exit") == 0))
	{
		if (list[1])
		{
			if (is_integer(list[1]) == 1)
				exit_code = _atoi(list[1]);
			else
				exit_code = 2;
		}
		handle_exit(list, str, ppid, exit_code, NULL, no_kill);
	}

	child = fork();
	if (child == -1)
		handle_exit(list, str, ppid, EXIT_FAILURE, "fork", terminate);

	if (child == 0)
	{	/* case where input to getline function is -1: CTRL + D */
		if (!list)
			handle_exit(list, NULL, ppid, EXIT_SUCCESS, NULL, terminate);
		if (list[0] && (_strcmp(list[0], "env") == 0 ||
			_strcmp(list[0], "printenv") == 0))
		{
			print_environment();
			handle_exit(list, str, ppid, EXIT_SUCCESS, NULL, no_kill);
		}
		/* handle commands */
		if (list[0] && (execve(list[0], list, environ) == -1))
			handle_exit(list, str, ppid, EXIT_FAILURE, "./shell", no_kill);
	}
	wait(&status); /* wait for child process to finish */
	if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_SUCCESS)
		exit_code = 2;
}

/**
 * print_environment - print environment when command is entered
 *
 * Return: void
*/
void print_environment(void)
{
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
}
