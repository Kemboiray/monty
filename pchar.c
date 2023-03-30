#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pchar - print the top item as a character
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (*stack == NULL)
	{
		clean();
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n;
	if (c < 0 || c > 127)
	{
		clean();
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}
