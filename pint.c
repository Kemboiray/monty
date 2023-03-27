#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - print the top item
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		clean();
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
