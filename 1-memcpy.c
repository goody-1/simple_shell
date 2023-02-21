#include "main.h"

/**
* _memcpy - function that copies memory area.
*
* Description: the _memcpy() function copies n bytes from
* memory area src to memory area dest
*
* @dest: memory area destination
* @src: memory area source
* @n: the number of bytes to be copied
*
* Return: a pointer to dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
