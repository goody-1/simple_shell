#include "main.h"

size_t split_sentence(char *str, char *delim);

/**
 * word_list - get a list of words from a string
 *
 * @str: the string to be broken into a list
 * @delim: the string of various delimeters in the string
 *
 * Return: return a double pointer to the list of words or NULL if error
*/

char **word_list(char *str, char *delim)
{
	size_t str_len, i, word_count, l_item = 0;
	char prev_char = '\0';
	char **list;

	if (!str || !delim)
		return (NULL);

	str_len = strlen(str);
	word_count = split_sentence(str, delim);
	printf("word_count: %ld\n", word_count);

	list = malloc(sizeof(char *) * (word_count + 1));
	if (!list)
		return (NULL);

	list[word_count] = NULL;

	for (i = 0; i < str_len; i++)
	{
		if (str[i] != '\0' && prev_char == '\0')
		{
			list[l_item] = str + i;
			l_item++;
		}
		prev_char = str[i];
	}

	i = 0;

	while (list[i])
	{
		trim_newline(list[i]);
		i++;
	}

	return (list);
}

/**
 * split_sentence - gets the number of items from a split sentence
 * @str: the string to be splitted
 * @delim: the delimeters to be used
 *
 * Return: the number of items in the split string or 0
 *			if no word or NULL delim
*/
size_t split_sentence(char *str, char *delim)
{
	size_t word_count = 0;

	if (!str || !delim)
		return (0);

	if (strtok(str, delim))
		word_count++;

	while (strtok(NULL, delim))
		word_count++;

	return (word_count);
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
