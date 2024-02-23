#include "main.h"

char **split_string(const char *str, const char *delimiters,
					size_t *num_words)
{
	char *copy, *token, *mem_error = "Memory";
	size_t capacity = 10; /* Initial capacity of the array */
	char **words;

	if (!str)
		perror_handler("NULL");

	copy = strdup(str);
	if (copy == NULL)
		perror_handler(mem_error);

	words = malloc(capacity * sizeof(char *));
	if (!words)
		perror_handler(mem_error);
	*num_words = 0;

	/* Tokenize the string using strtok */
	token = strtok(copy, delimiters);
	while (token != NULL)
	{
		if (*num_words >= capacity)
		{ /* Check if the array needs to be resized */
			capacity *= 2;
			words = realloc(words, capacity * sizeof(char *));
			if (words == NULL)
				perror_handler(mem_error);
		}

		/* Allocate memory for the token and store it in the array */
		words[(*num_words)++] = strdup(token);

		token = strtok(NULL, delimiters); /* Get the next token */
	}

	free(copy);
	return (words);
}

void perror_handler(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

char *trim_newline(char *str)
{
	size_t len = strlen(str);

	while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r'
			|| str[len - 1] == ' '))
	{
		str[len - 1] = '\0';
		len--;
	}

	return (str);
}
