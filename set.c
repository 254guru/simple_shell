#include "main.h"

/**
 * mysetenv - Sets the value of an environment variable.
 * @variable: The name of the variable to set.
 * @value: The value to assign to the variable.
 * @overwrite: Flag indicating whether to overwrite an existing variable.
 *
 * Return: 0 on success, 1 on failure.
 */
int mysetenv(char *variable, char *value, int overwrite)
{
	char *env_var;

	if (_getenv(variable) != NULL)
	{
		if (!overwrite)
		{
			_puts("setenv: variable already exists");
			return (1);
		}
	}

	env_var = malloc(strlen(variable) + strlen(value) + 2);
	if (env_var == NULL)
	{
		_puts("setenv: out of memory");
		return (1);
	}
	_strcpy(env_var, variable);
	_strcat(env_var, "=");
	_strcat(env_var, value);
	_putenv(env_var);
	free(env_var);
	return (0);
}

/**
 * myunsetenv - Unsets an environment variable.
 * @variable: The name of the variable to unset.
 * Return: 0 on success, 1 on failure.
 */
int myunsetenv(char *variable)
{
	if (_getenv(variable) == NULL)
	{
	_fputs("unsetenv: variable '", stderr);
	_fputs(variable, stderr);
	_fputs("' does not exist\n", stderr);
	return (1);
	}

	unsetenv(variable);

	return (0);
}
/**
 * putenv - Sets an environment variable.
 * @string: The string representing the environment variable to set.
 *
 * Return: 0 on success, -1 on failure.
 */
int _putenv(char *string)
{
	int result;
	char *equal_sign;

	if (string == NULL)
	return (-1);
	result = 0;

	equal_sign = _strchr(string, '=');

	if (equal_sign == NULL)
	{
	result = -1;
	}
	else
	{
	*equal_sign = '\0';
	result = setenv(string, equal_sign + 1, 1);
	*equal_sign = '=';
	}

	return (result);
}
