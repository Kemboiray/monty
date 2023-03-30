#include "monty.h"
#include <stdlib.h>

/**
 * rotr - rotates stack to the bottom
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;
	int bottom_int;

	if (temp == NULL || temp->next == NULL)
		return;

	while (temp->next)
		temp = temp->next;

	bottom_int = temp->n;

	while (temp->prev)
	{
		temp->n = temp->prev->n;
		temp = temp->prev;
	}

	temp->n = bottom_int;
}
