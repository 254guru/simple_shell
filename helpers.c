#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 *
 * Return: 1 on success, otherwise -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Calculate the length of a string
 *
 * @s: Pointer to the string to calculate the length of
 *
 * Return: Length of the string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
/**
 * free_args - Free the memory allocated for an array of strings
 * @args: Array of strings to free
 *
 * Return: void
 */
void free_args(char **args)
{
	char **temp = args;

	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(args);
}
/**
 * _strncpy - copies a string
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of characters to copy
 *
 * Return: pointer to destination buffer
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
/**
 * _strcpy - copies a string
 * @destination: string destination
 * @source: source string
 *
 * Return: destination
 */
char *_strcpy(char *destination, const char *source)
{
	char *ptr = destination;

	while (*source != '\0')
	{
		*ptr++ = *source++;
	}
	ptr = '\0';

	return (destination);
}

