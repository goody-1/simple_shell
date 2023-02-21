#include "main.h"

/**
 * main - main program for a simple shell
 *
 * Return: always 0;
 */


int main(void)
{

	loop();

	return (0);
}

/**
 * shell_exit - function to exit
 *
 * Return: 0
 */
int shell_exit(void)
{
	return (0);
}

/**
 * execute - function to execute command
 *
 * @args: argument to be executed
 *
 * Return: 1 or 0
 */

int execute(char **args)
{
	pid_t cpid;
	int status;
	char bin[1024] = "/bin/";
	char *store = args[0], *pathname;


	if (_strcmp(args[0], "exit") == 0)
	{
		free(*args);
		free(args);
		exit(EXIT_SUCCESS);
	}

	if (_strstr(args[0], bin) == NULL)
	{
		_strcat(bin, store);
		pathname = bin;
	}
	else
		pathname = args[0];

	cpid = fork();
	if (cpid == 0)
	{
		if (execve(pathname, args, environ) < 0)
		{
			perror("./shell");
			free(*args);
			free(args);
		}
		exit(EXIT_FAILURE);
	}
	else
		waitpid(cpid, &status, WUNTRACED);

	return (1);
}

/**
 * loop - looping the prompt
 *
 * Return: void
 */

void loop(void)
{
	size_t len = 0;
	ssize_t nread;
	char *line = NULL;
	char **args;
	int status = 1;

	while (status)
	{
		print_prompt();
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			_putchar('\n');
			exit(EXIT_SUCCESS);
		}
		/* start again is nothing is entered */
		if ((nread == 1 && line[0] == '\n') || line[0] == '\0')
		{
			continue;
		}
		args = split_line(line);
		status = execute(args);
		free(args);
	};
	free(line);
}
