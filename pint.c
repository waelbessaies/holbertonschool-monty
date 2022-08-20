#include "monty.h"
/**
 * pint - prints item of the stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being treated
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
