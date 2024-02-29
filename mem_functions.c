#include "main.h"

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

/**
 * _memmove - copy memory area
 *
 * @dest: destination
 * @src: source
 * @n: number of bytes from src to copy to dest
 *
 * Return: void
*/
void *_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;

	if (dest == src)
	{
		/* No need to move if source and destination overlap */
		return (dest);
	}

	if (s < d && d < s + n)
	{
		/* Overlapping memory, need to copy backwards */
		s += n - 1;
		d += n - 1;

		while (n-- > 0)
		*d-- = *s--;
	}
	else
	{
		/* No overlap, can copy forwards */
		while (n-- > 0)
			*d++ = *s++;
	}

	return (dest);
}
