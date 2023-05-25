#include "main.h"

/**
 * myrealloc - resize a memory block
 * @ptr: poiter to memory block to be reallocated
 * @size: new size of memory block
 *
 * Return: pointer to new memory block
 */
void *myrealloc(void *ptr, size_t size)
{
	if (ptr == NULL)
	{
		ptr = malloc(size);
	}
	else
	{
		if (size == 0)
		{
			free(ptr);
			ptr = NULL;
		}
		else
		{
			ptr = realloc(ptr, size);
		}
	}
	return (ptr);
}
