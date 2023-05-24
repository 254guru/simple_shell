#include "main.h"

/*
 * print_prompt - Prints a prompt to the stdout stream
 * Return: void
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
 *	0 if the input line is empty or end of input is reached.
 *	-1 if an error occurred while reading input.
 */
int prompt(char **line)
{
	size_t bufferSize = 0;
	ssize_t bytesRead;
	char *newLine = NULL;

	bytesRead = getline(&newLine, &bufferSize, stdin);

	if (bytesRead == -1)
	{
	if (feof(stdin))
	{
	free(newLine);
	_puts("\n");
	return (0);
	}
	else
	{
	perror("Input error");
	free(newLine);
	return (-1);
	}
	}
	else
	if (bytesRead == 0)
	{
	free(newLine);
	return (0);
	}
	else
	{
	if (newLine[bytesRead - 1] == '\n')
	newLine[bytesRead - 1] = '\0';

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
	(void)argc;
	(void)envp;
	program_name = argv[0];

	while (1)
	{
		print_prompt();
		if (prompt(&line) == -1)
			exit(0);

		args = split_line(line);
		if (args == NULL)
			continue;

		if (args != NULL && *args != NULL)
		{
			if (is_exit_command(args))
			{
				exit_status = get_exit_status(args);
				free(line);
				free_args(args);
				exit(exit_status);
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

/**
 * is_exit_command - Check if the command is "exit"
 * @args: Array of command-line arguments
 * Return: 1 if it is an exit command, 0 otherwise
 */
int is_exit_command(char **args)
{
	return (_strcmp(args[0], "exit") == 0);
}

/**
 * get_exit_status - Get the exit status from the command arguments
 * @args: Array of command-line arguments
 * Return: The exit status
 */
int get_exit_status(char **args)
{
	if (args[1] != NULL)
		return (_atoi(args[1]));
	else
		return (0);
}


