#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pop - delete top item in  stack
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%lu: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->prev = NULL;
	*stack = *stack->next;
	free(temp);
}
