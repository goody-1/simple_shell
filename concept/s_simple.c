#include "main.h"

int main(void)
{
	char *env[] = { NULL };
	char *str;
	char **list;
	pid_t child;
	int status;

	while (1)
	{
		str = trim_newline(prompt());
		list = word_list(str, " \t\n");
		printf("list[0]: %s, len: %ld\n", list[0], strlen(list[0]));

		child = fork();
		if (child == -1)
		{
			perror("Error");
			return (1);
		}
		if (child == 0)
		{
			if (execve(list[0], list, env) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
		free(list);
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
