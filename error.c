#include "monty.h"
/**
 * print_error - print error
 * @line:string containing the line
 *@line_number: number of the line
 * return void
 */
void print_error(char *line, unsigned int line_number)
{
    (void)line;

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
}
