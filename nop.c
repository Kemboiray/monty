#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * nop - do nothing
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void nop(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	if (line_number)
		return;
}
