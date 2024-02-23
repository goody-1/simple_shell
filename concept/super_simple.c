#include "main.h"


int main(void)
{
	char *str, **list;
	size_t num_words;
	pid_t ppid = getpid();

	printf("Parent pid is %u\n", ppid);

	if (isatty(STDIN_FILENO)) /* check if program is running interactively */
	{
		while (1)
		{
			str = prompt();
			list = split_string(str, " \t\n", &num_words);
			list[num_words] = NULL;

			handle_exec(list, str, ppid);
		}
	}
	else
	{ /* program is running in non-interactive mode */
		FILE *input_file = stdin;
		char *line;

		while ((line = read_line(input_file)) != NULL)
		{
			line[strcspn(line, "\n")] = '\0';

			str = strdup(line);
			list = split_string(str, " \t\n", &num_words);
			list[num_words] = NULL;

			handle_exec(list, str, ppid);
		}
	}

	free_list(list);
	free(str);
	return (0);
}

void handle_exec(char **list, char *str, int ppid)
{
	int status, no_kill = 0, terminate = 1;
	pid_t child = fork();

	if (child == -1)
		handle_exit(list, str, ppid, EXIT_FAILURE, "fork", no_kill);

	if (child == 0)
	{
		printf("My pid is %u and my parent pid is %u\n", getpid(), ppid);

		 /* case where input to getline function is -1: CTRL + D */
		if (!list[0])
			handle_exit(list, NULL, ppid, EXIT_SUCCESS, NULL, terminate);

		if (strcmp(list[0], "env") == 0 || strcmp(list[0], "printenv") == 0)
		{
			print_environment();
			handle_exit(list, str, ppid, EXIT_SUCCESS, NULL, no_kill);
		}
		if (strcmp(list[0], "exit") == 0)
			handle_exit(list, str, ppid, EXIT_SUCCESS, NULL, terminate);

		/* handle commands */
		if (execve(list[0], list, environ) == -1)
			handle_exit(list, str, ppid, EXIT_FAILURE, "./shell", no_kill);
	}
	else
		wait(&status); /* wait for child process to finish */
}

void print_environment(void)
{
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
}
