# Makefile

CC = gcc
CFLAGS = -Wall -Werror -pedantic
OBJ = stack.o opcode.o main.o

monty: $(OBJ)
	$(CC) $(CFLAGS) -o monty $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f monty $(OBJ)

