#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t str_len(char *str);
void skip_delim(const char *delim, size_t len_delim,
					size_t *counter, char *str);
char *strtok(char *str, const char *delim)
{

}

size_t str_len(char *str)
{
	unsigned int len;

	if (str == NULL)
		exit(98);

	for (len = 0; str[len] != '\0'; len++)
	;

	return (len);
}

void skip_delim(const char *delim, size_t len_delim,
					size_t *counter, char *str)
{
	size_t i = *counter, j = 0;

	while (i < (len_delim + *counter))
	{
		if (str[i] == delim[j])
			;
		else
			return;
		i++;
		j++;
	}
	*counter = i;
}
