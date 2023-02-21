#include "main.h"

/**
* _strstr - function that locates a substring.
* Description: finds the first occurrence of the substring needle
* in the string haystack. The terminating null bytes (\0)
* are not compared
* @string: haystack.
* @substring: needle
*
* Return:  pointer to the beginning of the located substring,
* or NULL if no such byte is found
*/


char *_strstr(register char *string, char *substring)
{
	register char *a, *b;

    /*
	* First scan quickly through the two strings looking for a
    * single-character match.  When it's found, then compare the
    * rest of the substring.
    */

	b = substring;
	if (*b == 0)
	{
		return (string);
	}
	for ( ; *string != 0; string += 1)
	{
		if (*string != *b)
		{
			continue;
		}
		a = string;
		while (1)
		{
			if (*b == 0)
			{
				return (string);
			}
			if (*a++ != *b++)
			{
				break;
			}
		}
		b = substring;
	}

	return (NULL);
}
