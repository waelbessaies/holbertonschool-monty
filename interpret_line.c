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
		flag = check_number_string(p);
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
/**
 * check_number_string - checks if string is a number
 * @string: string
 * Return: 1 or 0
 */
int check_number_string(char *string)
{
	while (string != NULL && *string != '\0')
	{
		if (*string == '-')
		{
			if (isdigit(*(string + 1)) == 0 && string--)
				return (1);
		}
		else if (*string != '-' && isdigit(*string) == 0)
			return (1);
		string++;
	}
	return (0);
}