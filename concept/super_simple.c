#include "main.h"


int main(void)
{
	char *str, **list;
	int status;
	size_t num_words;
	pid_t child, ppid = getpid();

	signal(SIGINT, handle_exit);
	while (1)
	{
		str = prompt();
		list = split_string(str, " \t\n", &num_words);
		list[num_words] = NULL;

		child = fork();
		if (child == -1)
		{
			perror("fork");
			return (1);
		}
		if (child == 0)
		{
			if (strcmp(list[0], "EOL") == 0)
			{
				free_list(list);
				kill(ppid, SIGINT);
				exit(EXIT_SUCCESS);
			}
			if (strcmp(list[0], "env") == 0 || strcmp(list[0], "printenv") == 0)
			{
				print_environment();
				free_list(list);
				free(str);
				exit(EXIT_SUCCESS);
			}
			if (strcmp(list[0], "exit") == 0)
			{
				free_list(list);
				free(str);
				kill(ppid, SIGINT);
				exit(EXIT_SUCCESS);
			}
			if (execve(list[0], list, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
		free_list(list);
		free(str);
	}
	return (0);
}

void free_list(char **list)
{
	size_t i = 0;

	if (list == NULL)
	{
		return;
	}

	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void handle_exit(int signum __attribute__((unused)))
{
	exit(EXIT_SUCCESS);
}
void print_environment()
{
    while (*environ != NULL) {
        printf("%s\n", *environ);
        environ++;
    }
}
