#include "main.h"

/**
 * split_line - function to split a line by spaces, tabs, newline
 *		or carriage return
 *
 * @line: the line to be splitted
 *
 * Return: pointer to pointer to char
 */

char **split_line(char *line)
{
	int buff_size = 1024, new_buff_size, position = 0;
	char **tokens = malloc(buff_size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("./shell");
		free(tokens);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buff_size)
		{
			new_buff_size = buff_size + 1024;
			tokens = _realloc(tokens, buff_size, new_buff_size * sizeof(char *));
			buff_size = new_buff_size;

			if (!tokens)
			{
				perror("./shell");
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}

	tokens[position] = NULL;

	return (tokens);
}
