#include "main.h"

/**
 * _strchr - locate character string
 * @str: string to be searched
 * @c: character to be located
 *
 * Return: pointer to first occurence of character in str
 * otherwise NULL if not found
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
/**
 * _strdup - duplicate a string
 * @str: source string to be duplicated
 *
 * Return: pointer to newly allocated string, otherwise NULL
 */
char *_strdup(const char *str)
{
	size_t length = _strlen(str);
	char *duplicate;

	duplicate = (char *)malloc((length + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);

	if (duplicate == NULL)
		return (NULL);

	_strcpy(duplicate, str);
	return (duplicate);
}
/**
 * _strcmp - compares two strings
 * @str1: char type
 * @str2: char type
 * Return: integer value
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

/**
 * _atoi - converts a string to an integer
 * @str: string to convert
 *
 * Return: result
 */
int _atoi(const char *str)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
/**
 * _strncmp - compare at most n characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: max number of chars to compare
 *
 * Return: integer...
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] && s2[i] && s1[i] == s2[i]; i++)
		;

	return (i == n ? 0 : (s1[i] - s2[i]));
}

