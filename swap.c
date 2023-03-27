#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap - swap the top two elements in the stack
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
