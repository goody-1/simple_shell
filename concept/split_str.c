#include "main.h"

char **split_string(const char *str, const char *delimiters,
					size_t *num_words)
{
	char *copy, *token;
	size_t capacity = 10; /* Initial capacity of the array */
	char **words;

	if (str == NULL)
	{
		perror("Null string");
		exit(EXIT_FAILURE);
	}

	copy = strdup(str);
	if (copy == NULL)
		perror_mem_alloc();

	words = malloc(capacity * sizeof(char *));
	if (words == NULL)
		perror_mem_alloc();
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
				perror_mem_alloc();
		}

		/* Allocate memory for the token and store it in the array */
		words[(*num_words)++] = strdup(token);

		token = strtok(NULL, delimiters); /* Get the next token */
	}

	free(copy);
	return (words);
}

void perror_mem_alloc(void)
{
	perror("Memory allocation error");
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
