#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sub - subtract the top elements from the second to top in the stack
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
