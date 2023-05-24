#include "main.h"
int token_count(char *command, char *delim)
{
        char *copy = NULL;
        char *token;
        int i = 0;

        copy = _strdup(command);
        token = strtok(copy, delim);

        while (token != NULL)
        {
                i++;
                token = strtok(NULL, delim);
        }
        free(copy);
        return (i);
}
