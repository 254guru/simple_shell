#include "main.h"

/**
 * print - main function
 *
 * Return: 0
 */

int print(void)
{
	char *message;
	int len = 14;

	message = "Hello, World!\n";

	write(STDOUT_FILENO, message, len);
	return (0);
}
