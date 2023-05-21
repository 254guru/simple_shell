#include "main.h"
#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 200

/**
 * get_command_path - gets the full path of a command using PATH variable
 * @command: command to find
 *
 * Return: full path of the command, otherwise NULL
 */

char *get_command_path(char *command)
{
	char *path;
	char *dir;
	char *full_path;
	char *token;

	if (_strchr(command, '/') != NULL)
	{
		return (_strdup(command));
	}
	path = getenv("PATH");

	if (path == NULL)
	{
		_fprintf(stderr, "Error retrieving PATH variable\n");
		return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		dir = _strdup(token);
		full_path = malloc(_strlen(dir) + _strlen(command) + 2);

		if (full_path == NULL)
		{
			_fprintf(stderr, "Allocation error\n");
			free(dir);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(dir);
			return (full_path);
		}
		free(full_path);
		free(dir);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
/**
 * build_command_path - BUILD THE FULL PATH OF A COMMAND
 * @directory: directory to prepend the command
 * @command: command to append to the directory
 *
 * Return: full path of the command
 */
char *build_command_path(char *directory, char *command)
{
	size_t directory_len = _strlen(directory);
	size_t command_len = _strlen(command);
	size_t path_len = directory_len + command_len + 2;
	char *path;

	path = malloc(path_len);
	if (path == NULL)
	{
		_fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	_strncpy(path, directory, directory_len);
	path[directory_len] = '/';
	_strncpy(path + directory_len + 1, command, command_len);
	path[path_len - 1] = '\0';

	return (path);
}
