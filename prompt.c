#include "main.h"

/**
 * print_prompt - function to print prompt
 *
 * Return: no return (void)
 */

void print_prompt(void)
{
	char *prompt = "#cisfun$ ";
	int i = 0;

	while (prompt[i] != '\0')
	{
		_putchar(prompt[i]);
		i++;
	}

}
