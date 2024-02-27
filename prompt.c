#include "main.h"

/**
 * prompt - This is a function that can display the prompt.
 * Return: return always success.
 *
 */
char *prompt(void)
{
	char *prompt = "#custom$ ", *input = NULL;
	size_t len = 0;
	ssize_t nread;

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	nread = getline(&input, &len, stdin);

	if (nread == -1) /* get EOF or EOL; CTRL + D */
	{
		free(input);
		return (NULL);
	}
	return (input);
}

/**
 * read_line - function used to read the line of text from a standard input
 * @input: user input
 * Return: return always success
 */

char *read_line(FILE *input)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, input);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
