#include "main.h"
#include <signal.h>

volatile sig_atomic_t flag = 0;

void handle_signal(int signal)
{
    if (signal == SIGINT)
    {
        flag = (1);
    }
}

/*
 * print_prompt - Prints a prompt to the stdout stream
 * Return: 0
 */
int print_prompt(void)
{
    char *prompt = "($) ";

    ssize_t bytesWritten = write(STDOUT_FILENO, prompt, strlen(prompt));
    if (bytesWritten == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}
/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 * Return: Always 0 (success)
 */
int prompt(char **line)
{
    size_t bufferSize = 0;
    ssize_t bytesRead;
    char *newLine = NULL;

    bytesRead = getline(&newLine, &bufferSize, stdin);

<<<<<<< HEAD
    if (bytesRead == -1)
    {
        if (flag)
        {
            free(newLine);
            return (-1);
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
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
=======
	if (bytesRead == -1)
	{
	free(newLine);
	return (-1);
	}
	else if (bytesRead == 0)
	{
	free(newLine);
	if (feof(stdin))
	{
	printf("Control-D (EOF) encountered. Exiting shell.\n");
	exit(0);
	}
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
>>>>>>> 21576d2886bdfcf96897cd8abe30f91ed3d803bb
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
    char *line = NULL;
    char **args;
    int status;
    (void)argc;
    (void)envp;
    program_name = argv[0];
    signal(SIGINT, handle_signal);

    while (1)
    {
        print_prompt();

        if (prompt(&line) == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        args = split_line(line);
        if (args == NULL)
        {
            continue;
        }

        if (args != NULL && *args != NULL)
        {
            if (_strcmp(args[0], "exit") == 0)
            {
                if (args[1] != NULL)
                {
                    int exit_status = _atoi(args[1]);
                    free(line);
                    free_args(args);
                    exit(exit_status);
                }
                else
                {
                    free(line);
                    free_args(args);
                    exit(EXIT_SUCCESS);
                }
            }

            status = execute(args);
            free_args(args);
        }

        free(line);
        line = NULL;

        if (status == EXIT_SUCCESS)
        {
            continue;
        }
    }

    return (0);
}
