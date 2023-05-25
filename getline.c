#include "main.h"
#define BUFFER_SIZE 1024
/**
 * mygetline - reads a line from STDIN
 * @lineptr: *pointer to storage buffer
 * @n: pointer to size of buffer
 * @stream: file to read line from
 *
 * Return: chars read, otherwise -1
 */
ssize_t mygetline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = NULL;
	ssize_t bytes_read;
	size_t line_size = 0;

	line = malloc(*n);
	if (line == NULL)
	{
		return (-1);
	}
	while ((bytes_read = getc(stream)) != EOF)
	{
		if (bytes_read == '\n')
		{
			break;
		}
		if (line_size == *n)
		{
			*n *= 2;
			line = myrealloc(line, *n);
			if (line == NULL)
			{
				return (-1);
			}
		}
		line[line_size++] = bytes_read;
	}
	if (bytes_read == EOF)
	{
		line[line_size++] = '\0';
	}
	*lineptr = line;

	return (line_size);
}
