#include "main.h"

void free_list(char **list)
{
	size_t i = 0;

	if (!list)
		return;

	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void handle_exit(char **list, char *str, int ppid,
					int exit_status, char *p_err, int terminate)
{
	signal(SIGTERM, handle_kill);

	if (list)
		free_list(list);
	if (str)
		free(str);
	if (terminate)
		kill(ppid, SIGINT);
	if (p_err)
		perror(p_err);
	exit(exit_status);
}
void handle_kill(int signum __attribute__((unused)))
{
	exit(EXIT_SUCCESS);
}
