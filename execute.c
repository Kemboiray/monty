#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute - parse and execute instructions
 * @tokens: array of tokens from each line of instruction
 * @line_number: line number of instruction
 *
 * Return: void.
 */
stack_t *top = NULL;
int item = 0;

stack_t *execute(char **tokens, size_t line_number)
{
	char *opcode = tokens[0];
	char *arg = tokens[1];
	unsigned int i;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	arg[strlen(arg) - 1] = 0;
	for (i = 0; instruction[i].opcode; i++)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
		{
			if (strcmp(instruction[i].opcode, "push") == 0)
			{
				if (is_number(arg) == 0)
				{
					free_list(top);
					fprintf(stderr, "L%lu: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				item = atoi(arg);
			}
			instruction[i].f(&top, line_number);
			return (top);
		}
	}

	free_list(top);
	fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
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

	for (i = 0; str[i]; i++)
	{
		if (!(strchr("-+0123456789 \t", str[i])))
			return (0);
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] > 47 && str[i] < 58)
			return (1);
	}
	return (0);
}
