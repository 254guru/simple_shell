#include "main.h"

/**
 * cd - Changes the current directory.
 * @directory: The directory path to change to.
 * Return: On success, 0. On error, 1.
 */
int cd(char *directory)
{
	char *cwd = getcwd(NULL, 0);
	int rc = chdir(directory);

	if (directory == NULL)
	directory = _getenv("HOME");

	if (directory == NULL)
	{
	_fputs("cd: directory does not exist\n", stderr);
	return (1);
	}

	if (rc != 0)
	{
	_fputs("cd: cannot change directory\n", stderr);
	return (1);
	}

	if (cwd == NULL)
	{
	_fputs("cd: cannot get current working directory\n", stderr);
	return (1);
	}

	mysetenv("PWD", cwd, 1);

	return (0);
}
