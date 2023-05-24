#include "main.h"

/*
 * print_prompt - Prints a prompt to the stdout stream
 *
 * Return: None.
 */
void print_prompt(void)
{
	char *prompt = "($) ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
}
/**
 * prompt - Reads a line of input from the user.
 * @line: Pointer to the variable where the input line will be stored.
 * Return: 1 if a line of input was successfully read.
 *		0 if the input line is empty or end of input is reached.
 *		-1 if an error occurred while reading input.
 */
int prompt(char **line)
{
	size_t bufferSize = 0;
	ssize_t bytesRead;
	char *newLine = NULL;

	bytesRead = getline(&newLine, &bufferSize, stdin);

	if (bytesRead == -1)
	{
	free(newLine);
	return (-1);
	}
	else if (bytesRead == 0)
	{
	free(newLine);
	return (0);
	}
	else
	{
	if (newLine[bytesRead - 1] == '\n')
	{
	newLine[bytesRead - 1] = '\0';
	}
	free(*line);
	*line = newLine;
	return (1);
	}
}
/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 * Return: Always 0 (success)
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL, **args;
	int exit_status;
	int status;
	(void) argc, 
	(void)envp;
	program_name = argv[0];

	while (1)
	{
		print_prompt();
		if (prompt(&line) == -1)
		{
			exit(0);
		}
		args = split_line(line);
		if (args == NULL)
			continue;
		if (args != NULL && *args != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				if (args[1] != NULL)
				{
					exit_status = _atoi(args[1]);

					free(line);
					free_args(args);
					exit(exit_status);
				}
				else
				{
					free(line);
					free_args(args);
					exit(0);
				}
			}
			status = execute(args);
			free_args(args);
		}

		free(line);
		line = NULL;
		if (status == EXIT_SUCCESS)
			continue;
		else
			break;
	}
	return (0);
}
