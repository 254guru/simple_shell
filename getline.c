#include "main.h"
#define BUFFER_SIZE 1024
/**
 * mygetline - reads a line from STDIN
 *
 * Return: void
 */
char *mygetline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index;
	static int buffer_size;
	char *line = NULL;
	int line_index = 0;
	char current_char;

	while (1)
	{
		if (buffer_index >= buffer_size)
	{
		buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		buffer_index = 0;
		if (buffer_size <= 0)
			break;
	}
		current_char = buffer[buffer_index++];

		if (current_char == '#' || current_char == '\n' || current_char == '\0')
			break;
		line = myrealloc(line, (line_index + 1) * sizeof(char));
		line[line_index++] = current_char;
	}

	if (line_index > 0)
	{
		line = myrealloc(line, (line_index + 1) * sizeof(char));
		line[line_index] = '\0';
	}

	return (line);
}
