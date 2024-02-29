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

char *_strcpy(char *dest, const char *src)
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

/**
* _strncmp - compares n bytes of two strings
*
* Description: should work exactly like strncmp
*
* @s1: first string to be compared
* @s2: second string to be compared
* @n: number of characters to compare
*
* Return: an interger: 0 to mean they are equal,
*			1 to mean the first string is greater, -1 otherwise
*/

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}

	/* if specified number of characters is not reached */
	if (i < n)
	{
		if (s1[i] != '\0')
			return (1);
		else if (s2[i] != '\0')
			return (-1);
	}

	return (0);
}

/**
 * _strdup - duplicates the string
 * @src: source pointer
 * Return: duplicate copy
 */
char *_strdup(const char *src)
{
	size_t len = _strlen(src) + 1; /* Include space for the null terminator */
	char *dest = malloc(len);

	if (dest == NULL)
		return (NULL);

	return (_strcpy(dest, src));
}
