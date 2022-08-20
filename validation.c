#include "monty.h"

/**
 * valid - checks if the syntax is valid
 * @function_name: name of the function that can be "push"
 * Return: 0 (function is unknown) on failure and 1 on success
 */
int valid(char *function_name)
{
	char name[][10] = {"push", "pall", "pint", "pop",
		"swap", "add", "nop", "sub", "div", "mul", "mod", ""};
	unsigned int i;

	for (i = 0; name[i][0] != '\0'; i++)
	{
		if (strcmp(name[i], function_name) == 0)
			return (1);
	}
	return (0);
}