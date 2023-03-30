#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pstr - print the stack
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar(10);
}
