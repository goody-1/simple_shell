#include "main.h"

/**
 * free_list - function to free list.
 * @list: a pointer to the list to be freed.
 * Return: NULL
 */

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

/**
 * handle_exit - function that terminates the programme
 * @list: a pointer to the list
 * @exit_status: terminate a process
 * @str: pointer to a string
 * @ppid: parent process id
 * @terminate: terminates a process
 * @p_err: descriptive message to identify error
 */
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
/**
 * handle_kill - function used in terminating an initiatted process
 * @signum: unique identifier
 */
void handle_kill(int signum __attribute__((unused)))
{
	exit(EXIT_SUCCESS);
}

/**
 * is_integer - function to test whether a string contains numbers only
 * @s: string to be tested
 *
 * Return: 0 if at least a character is not digit, 1 if all are digits
*/
int is_integer(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
* _atoi - convert a string to an integer.
* @s: source pointer
* Return: void
*/

int _atoi(char *s)
{
	int i = 0;
	unsigned int res = 0;
	int flag = 1;

	while (s[i] != '\0')
	{
		if (s[i - 1] == '-')
			flag *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10 + (s[i] - '0');
			if (s[i + 1] == ' ')
				break;
		}

		i++;
	}
	return (flag * res);
}
