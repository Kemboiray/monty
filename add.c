#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add - add the top two elements in the stack
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
