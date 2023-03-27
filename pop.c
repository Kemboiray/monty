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
		clean();
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->next)
		temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
