#include "monty.h"
/**
 * pop - removes the last element of a stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void pop(stack_m **stack, unsigned int line_number)
{
	stack_m *ptr;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = NULL;
	free(ptr);
}
