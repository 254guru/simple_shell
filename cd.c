#include "main.h"

int cd(char *directory) {
  char *cwd = getcwd(NULL, 0);
  int rc = chdir(directory);
	if (directory == NULL) {
    directory = getenv("HOME");
  }

  if (directory == NULL) {
    fprintf(stderr, "cd: directory '%s' does not exist\n", directory);
    return 1;
  }

  if (rc != 0) {
    fprintf(stderr, "cd: cannot change directory to '%s'\n", directory);
    return 1;
  }

  if (cwd == NULL) {
    fprintf(stderr, "cd: cannot get current working directory\n");
    return 1;
  }
  mysetenv("PWD", cwd, 1);

  return 0;
}

