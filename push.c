#include "monty.h"
/**
 * push - push the elements to a linked list
 * @stack: the pointer to stack's first element
 * @line_number: line of the file being processed.
 * Return: void
 */

void push(stack_m **stack, unsigned int line_number)
{
	(void)line_number;

	if (input != NULL)
	{
		stack_m *ptr = malloc(sizeof(stack_m));
		ptr->n = atoi(input);
		ptr->next = (*stack);
		ptr->prev = NULL;

		if ((*stack) != NULL)
		{
			(*stack)->prev = ptr;
		}
		(*stack) = ptr;
	}
}
