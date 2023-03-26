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
	unsigned int i, j;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; instruction[i].opcode; i++)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
		{
			if (strcmp(instruction[i].opcode, "push") == 0)
			{
				item = atoi(arg);
				if (item == 0)
				{
					for (j = 0; arg[j]; j++)
					{
						if (!(strchr("-+ \t0", arg[j])))
						{
							free_list(top);
							fprintf(stderr, "L%lu: usage: push integer\n", line_number);
							exit(EXIT_FAILURE);
						}
						if (arg[j] == '0')
							break;
					}
				}
			}
			instruction[i].f(&top, line_number);
			return (top);
		}
	}

	free_list(top);
	fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
