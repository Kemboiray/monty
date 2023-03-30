#include "monty.h"
#include <stdlib.h>

/**
 * rotl - rotates stack to the top
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;
	int top_int;

	if (temp == NULL || temp->next == NULL)
		return;
	top_int = temp->n;
	while (temp->next)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}
	temp->n = top_int;
}
