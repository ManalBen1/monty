// opcode.c
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack stack; // Global stack instance

void process_opcodes(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    stack.top = -1; // Initialize stack top

    process_opcodes(argv[1]);

    return 0;
}

void process_opcodes(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char opcode[5]; // Assuming the maximum length of opcode is 4
    int value, line_number = 1;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (opcode[0] == '#') { // Ignore comments
            while (fgetc(file) != '\n') {}
            line_number++;
            continue;
        }

        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) == 1) {
                push(value, line_number);
            } else {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else if (strcmp(opcode, "pint") == 0) {
            pint(line_number);
        } else if (strcmp(opcode, "pop") == 0) {
            pop(line_number);
        } else if (strcmp(opcode, "swap") == 0) {
            swap(line_number);
        } else if (strcmp(opcode, "add") == 0) {
            add(line_number);
        } else if (strcmp(opcode, "nop") == 0) {
            nop();
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    fclose(file);
}
