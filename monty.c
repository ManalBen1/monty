#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1000

typedef struct {
    int stack[STACK_SIZE];
    int top;
} Stack;

Stack stack;

void push(int value) {
    if (stack.top >= STACK_SIZE) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stack.stack[++stack.top] = value;
}

void pall() {
    int i;

    for (i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.stack[i]);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_number = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    stack.top = -1; // Initialize an empty stack

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;

        // Tokenize the line
        char *token = strtok(line, " \n");

        if (token == NULL || *token == '#') {
            // Ignore empty lines or lines starting with #
            continue;
        } else if (strcmp(token, "push") == 0) {
            token = strtok(NULL, " \n");
            if (token == NULL || !atoi(token)) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }

            push(atoi(token));
        } else if (strcmp(token, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    if (line) {
        free(line);
    }

    return 0;
}
