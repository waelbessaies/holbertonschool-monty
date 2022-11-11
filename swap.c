#include "monty.h"
void swap(stack_m **stack, unsigned int line_number)
{
	stack_m *p = (*stack);
	int length = 0;

	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_m *node1 = (*stack);
		stack_m *node2 = (*stack)->next;

		node1->next = node2->next;
		node1->prev = node2;

		node2->prev = NULL;
		node2->next = node1;

		(*stack) = node2;
	}
}