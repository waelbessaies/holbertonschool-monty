#include "monty.h"
/**
 * interpret_line - intrepets the line
 *@line: string containnig the line
 *@line_number:number of line
 *@stack: pointer to the stack head
 * Return: void
 */
void interpret_line(char *line, unsigned int line_number, stack_m **stack)
{
	char *function_name;
	int inoperative;

	function_name = strtok(line, " \t\n");

	if (function_name != NULL)
	{
		input = strtok(NULL, " \t\n");

		inoperative = valid(function_name);
		if (strcmp(function_name, "push") == 0 && !input)
		{

			fprintf(stderr, "L%d: usage: push integer ", line_number);
			free_stack(stack);
			stack = NULL;
			free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		else if (inoperative != VALID)
		{
			print_error(line, line_number);
			free_stack(stack);
			stack = NULL;
			free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		else
			getopfunc(function_name, line_number, stack);
	}
}
