#include "main.h"


/**
* _strlen - returns the length of a string
* @s: pointer to string
* Return: void
*/

size_t _strlen(const char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
	;

	return (i);
}

/**
* _strcpy - copies the string pointed to by src,
* including the terminating null byte (\0),
* to the buffer pointed to by dest
*
* @src: source pointer
* @dest: destination pointer
* Return: void
*/

char *_strcpy(char *dest, char *src)
{
	int len = 0, i = 0;

	while (src[len] != '\0')
		len++;

	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';

	return (dest);
}

/**
* _strcmp - compares two strings
*
* Description: should work exactly like strcmp
*
* @s1: first string to be compared
* @s2: second string to be compared
*
* Return: an interger: 0 to mean they are equal,
*			1 to mean the first string is greater, -1 otherwise
*/

int _strcmp(char *s1, char *s2)
{
	size_t i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}

	/* Check for remaining characters in either string */
	if (s1[i] != '\0')
		return (1);
	else if (s2[i] != '\0')
		return (-1);

	return (0);
}

char *_strdup(const char *src)
{
	size_t len = _strlen(src) + 1; // Include space for the null terminator
	char *dest = malloc(len);

	if (dest == NULL)
		return NULL;

	return _strcpy(dest, src);
}

/**
 * _realloc - reallocates memory block, using malloc
 *
 * @ptr: pointer to memory previously allocated
 * @old_size: previous memory size
 * @new_size: new memory size
 *
 * Return: pointer to allocated memory
 *          or NULL if size is 0 or malloc fails or nmemb is 0
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	unsigned char *byte_mem;
	unsigned int i, size;

	if (new_size == old_size)
		return (ptr);
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	mem = malloc(new_size);
	if (mem == NULL)
		return (NULL);

	if (ptr == NULL)
		return (mem);

	/* let size to be used be the minimum of old and new sizes */
	size = new_size < old_size ? new_size : old_size;
	byte_mem = (unsigned char *)mem;

	for (i = 0; i < size; i++)
		byte_mem[i] = ((unsigned char *)ptr)[i];

	free(ptr);
	return (mem);
}
