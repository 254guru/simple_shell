#include "main.h"

int mysetenv(char *variable, char *value, int overwrite) {
  char *env_var;

	if (getenv(variable) != NULL) {
    if (!overwrite) {
      fprintf(stderr, "setenv: variable '%s' already exists\n", variable);
      return 1;
    }
  }

  env_var = malloc(strlen(variable) + strlen(value) + 2);
  if (env_var == NULL) {
    fprintf(stderr, "setenv: out of memory\n");
    return 1;
  }
  strcpy(env_var, variable);
  strcat(env_var, "=");
  strcat(env_var, value);
  putenv(env_var);

  return 0;
}

int myunsetenv(char *variable) {
  if (getenv(variable) == NULL) {
    fprintf(stderr, "unsetenv: variable '%s' does not exist\n", variable);
    return 1;
  }

  unsetenv(variable);

  return 0;
}

