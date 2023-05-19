#include "main.h"

/**
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	char *message;
	int len = 14;

	message = "Hello, World!\n";

	write(STDOUT_FILENO, message, len);
	return (0);
}
