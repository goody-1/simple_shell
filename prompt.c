#include "main.h"

/**
 * print_prompt - function to print prompt
 *
 * Return: no return (void)
 */

void print_prompt(void)
{
	char *prompt = "";

	write(2, prompt, strlen(prompt));

}
