#include "monty.h"

/**
 * add - add 2 numbers
 * @stack:stack
 * @line_number: line number
 */

void add(stack_m **stack, unsigned int line_number)
{
	stack_m *p = (*stack);
	int length = 0;
	int sum = 0;

	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = sum;
		pop(stack, line_number);
	}
}