#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * push - push an item to stack
 * @stack: pointer to stack (linked list)
 * @line_number: line number of instruction
 *
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	if (is_number(global.arg) == 0)
	{
		clean();
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		clean();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(global.arg);
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * is_number - checks if a string is a number
 * @str: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
unsigned int is_number(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (strchr("0123456789", str[i]) && strchr(" \t", str[i + 1]))
			break;
		if (!(strchr("-+0123456789 \n\t", str[i])))
			return (0);
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] > 47 && str[i] < 58)
			return (1);
	}
	return (0);
}
