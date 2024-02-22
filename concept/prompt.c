#include "main.h"

char *prompt(void)
{
	char *prompt = "#cisfun$ ", *input = NULL;
	size_t len = 0;
	ssize_t nread;


	printf("%s", prompt);
	nread = getline(&input, &len, stdin);

	if (nread == -1)
	{
		free(input);
		return ("EOL");
	}

	return (input);
}
