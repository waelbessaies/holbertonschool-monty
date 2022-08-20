#include "monty.h"
/**
* free_stack - print error
* @stack: pointer to stack head
* return void
*/
void free_stack(stack_t **stack)
{
stack_t *ptr, *tmp;
ptr = *stack;
while (ptr)
{
tmp = ptr;
ptr = ptr->next;
free(tmp);
}


}
