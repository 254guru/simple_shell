#include "main.h"

#define MAX_ARGS 64
#define MAX_ARG_LENGTH 16

/**
 * split_line - Split a line into separate arguments
 *
 * @line: The line to be split
 *
 * Return: Array of strings containing the arguments
 */
char **split_line(char *line)
{
	char *DELIM = " \t\r\n\a";
	char *arg;
	int i = 0;
	int j;
	char **args = malloc((MAX_ARGS + 1) * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	for (arg = strtok(line, DELIM);
	arg != NULL && i < MAX_ARGS;
	arg = strtok(NULL, DELIM))
	{
		args[i] = malloc((MAX_ARG_LENGTH + 1) * sizeof(char));
		if (args[i] == NULL)
		{
			perror("malloc failed");
			for (j = 0; j < i; j++)
			{
				free(args[j]);
			}
			free(args);
			return (NULL);
		}
		_strncpy(args[i], arg, MAX_ARG_LENGTH);
		args[i][MAX_ARG_LENGTH] = '\0';
		i++;
	}
	args[i] = NULL;
	return (args);
}

