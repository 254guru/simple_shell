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
	static char buffer[BUFFER_SIZE];
	static size_t position;
	size_t bytes_read, line_size;
	size_t new_position = position;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	while ((bytes_read = read(fileno(stream), buffer + position,
					BUFFER_SIZE - position)) > 0)
	{
		position += bytes_read;
		while (new_position > 0 && buffer[new_position - 1] != '\n')
		{
			new_position--;
		}
		if (new_position > 0)
		{
			line_size = new_position - position;
			memcpy(*lineptr, buffer + position, line_size);
			(*lineptr)[line_size] = '\0';

			position = new_position + 1;

			return (line_size);
		}
	}
	if (bytes_read == 0)
	{
		return (-1);
	}
	line_size = position;
	memcpy(*lineptr, buffer + position, line_size);
	(*lineptr)[line_size] = '\0';
	position = 0;

	return (line_size);

}
