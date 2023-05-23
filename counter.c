#include "main.h"
#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 200

void process_command(char *command, int counter) {
    char *command_path = get_command_path(command);
    int status;

    if (command_path != NULL) {
        pid_t pid = fork();
        if (pid == 0) {
            execl(command_path, command_path, NULL);
            fprintf(stderr, "%s: command not found\n", command);
            exit(0);
        } else if (pid < 0) {
            fprintf(stderr, "Error forking\n");
            exit(1);
        } else {
            waitpid(pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                printf("%d: %s executed successfully\n", counter, command);
            } else {
                fprintf(stderr, "%d: %s: command not found\n", counter, command);
            }
        }

        free(command_path);
    } else {
        fprintf(stderr, "%d: %s: command not found\n", counter, command);
    }
}

void interactive_mode() {
    char command[MAX_COMMAND_LENGTH];
    int counter = 1;

    while (1) {
        printf("./hsh: %d ", counter);
        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        process_command(command, counter);
        counter++;
    }
}

void non_interactive_mode(char *filename) {
    FILE *file = fopen(filename, "r");
     char command[MAX_COMMAND_LENGTH];
    int counter = 1;

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(command, sizeof(command), file)) {
        command[strcspn(command, "\n")] = '\0';
        process_command(command, counter);
        counter++;
    }

    fclose(file);
}

