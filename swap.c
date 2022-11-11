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
}