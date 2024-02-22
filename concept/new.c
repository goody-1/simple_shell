#include "main.h"

size_t tokenize(char *str, char *delim)
{
    size_t word_count = 0;

    if (strtok(str, delim) != NULL)
        ++word_count;

    while (strtok(NULL, delim) != NULL)
        word_count++;

    return (word_count);
}

char **word_list(char *str, char *delim)
{
	char **arr = NULL;
	size_t arr_iter = 0;
	size_t arr_size = 0;
	size_t str_size = strlen(str);
	char prev_char = '\0';

	arr_size = tokenize(str, delim) + 1;
	arr = malloc(sizeof (char *) * arr_size);

	if (arr == NULL)
	{
		return (NULL);
	}

	for (size_t str_iter = 0; str_iter < str_size; ++str_iter)
	{
		if (str[str_iter] != '\0' && prev_char == '\0')
		{
			arr[arr_iter] = str + str_iter; /* pointer arithmetic */
			++arr_iter;
		}
		prev_char = str[str_iter];
	}
	arr[arr_iter] = NULL;

	return (arr);
}

int main(void)
{
    char sentence[] = "This is a sample sentence.";
	char delimiters[] = " ";

	char **words = word_list(sentence, delimiters);

    for (size_t i = 0; words[i] != NULL; i++) {
		printf("Word[%zu]: %s ,  %d\n", i, words[i], (int)(words + i));
	}

	free(words);
	return 0;
}
