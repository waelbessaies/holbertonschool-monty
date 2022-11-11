#include "monty.h"
#include <ctype.h>
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
	char *p;
	int flag = 0;

	function_name = strtok(line, " \t\n");
	if (function_name != NULL)
	{
		input = strtok(NULL, " \t\n");
		inoperative = valid(function_name);
		p = input;
		while (p != NULL && *p != '\0')
		{
			if (*p == '-')
			{
				if (isdigit(*(p + 1)) == 0 && p--)
					flag = 1;
			}
			else if (*p != '-' && isdigit(*p) == 0)
				flag = 1;
			p++;
		}
		if (strcmp(function_name, "push") == 0 && (!input || flag == 1))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
