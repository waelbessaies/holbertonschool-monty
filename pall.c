#include "monty.h"
/**
 * pall - prints the elements of a linked list
 * @stack: the pointer to stack's first element
 * @line_number: line of the file being processed.
 * Return: void
 */

void pall(stack_m **stack, unsigned int line_number)
{
    stack_m *ptr;

    (void)line_number;
    if (stack == NULL || *stack == NULL)
        return;
    ptr = *stack;
    while (ptr)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
}
