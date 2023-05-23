#include "main.h"

/**
 * execute - Execute a command with arguments
 *
 * @args: Array of strings containing command and arguments
 *
 * Return: Status code of the command execution
 */
int execute(char **args)
{
	if (args[0] == NULL)
	{
	return (1);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
	return (execute_exit(args));
	}
	else if (strcmp(args[0], "env") == 0)
	{
	return (execute_env());
	}
	else
	{
	return (execute_command(args));
	}
}

/**
 * execute_exit - Handle the "exit" command
 *
 * @args: Array of strings containing command and arguments
 *
 * Return: Status code of the command execution
 */
int execute_exit(char **args)
{
	if (args[1] != NULL)
	{
	int status = _atoi(args[1]);

	exit(status);
	}
	else
	{
	exit(EXIT_SUCCESS);
	}
}

/**
 * execute_env - Handle the "env" command
 *
 * Return: Status code of the command execution
 */
int execute_env(void)
{
	char **env = __environ;

	while (*env != NULL)
	{
	fputs(*env, stdout);
	fputc('\n', stdout);
	env++;
	}
	return (1);
}

/**
 * execute_command - Execute a command
 *
 * @args: Array of strings containing command and arguments
 *
 * Return: Status code of the command execution
 */
int execute_command(char **args)
{
	char *command_path = get_command_path(args[0]);

	if (command_path != NULL)
	{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
	if (execve(command_path, args, NULL) == -1)
	{
	perror("execve");
	exit(EXIT_FAILURE);
	}
	}
	else if (child_pid < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
	free(command_path);
	}
	else
	{
	fputs(program_name, stdout);
	fputs(": Command not found: ", stdout);
	fputs(args[0], stdout);
	fputc('\n', stdout);
	}
	return (0);
}

