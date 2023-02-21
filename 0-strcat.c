#include "main.h"

/**
* _strcat - concatenates two strings
*
* Description: This function appends the src string to the dest string,
* overwriting the terminating null byte (\0) at the end of dest,
* and then adds a terminating null byte
*
* @dest: this is the destination of the result
* @src: this is the string to be added to the dest
*
* Return: a pointer to the resulting string dest;
*/


char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, m;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		j++;
	}

	for (m = 0; m < j; m++)
	{
		dest[i] = src[m];
		i++;
	}

	return (dest);
}

