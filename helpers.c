#include "main.h"

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
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: string to compare with str1
 *
 * Return: void
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

