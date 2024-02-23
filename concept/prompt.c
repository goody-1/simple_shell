#include "main.h"

char *prompt(void)
{
	char *prompt = "#custom$ ", *input = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("%s", prompt);
	nread = getline(&input, &len, stdin);

	if (nread == -1) /* get EOF or EOL; CTRL + D */
	{
		free(input);
		return (NULL);
	}
	return (input);
}

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
