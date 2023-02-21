#include "main.h"

/**
* _strcmp - compares two strings
*
* Description: should work exactly like strcmp
*
* @s1: first string to be compared
* @s2: second string to be compared
*
* Return: a pointer to the resulting string dest;
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0, result;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;

	if (s1[i] < s2[i])
		result = -15;
	else if (s1[i] > s2[i])
		result = 15;
	else
		result = 0;

	return (result);
}
