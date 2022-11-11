#ifndef MONTY_H
#define MONTY_H

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define VALID 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_m; // changed type from stack_t to stack_m

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_m **stack, unsigned int line_number);
} instruction_t;

void interpret_line(char *line, unsigned int line_number, stack_m **stack);
int digits(char *input);
char *input;
int valid(char *function_name);
void print_error(char *line, unsigned int line_number);
void getopfunc(char *function_name, unsigned int line_number, stack_m **stack);
void free_stack(stack_m **stack);

void push(stack_m **stack, unsigned int line_number);

void pall(stack_m **stack, unsigned int line_number);
void pint(stack_m **stack, unsigned int line_number);
void pop(stack_m **stack, unsigned int line_number);
void nop(stack_m **stack, unsigned int line_number);
int check_number_string(char *string);
#endif
