#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute - parse and execute instructions
 * @opcode: command given by user
 * @line_number: line number of instruction
 *
 * Return: void.
 */

void execute(char *opcode, unsigned int line_number)
{
	unsigned int i;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pstr", pstr},
		{"pint", pint},
		{"pchar", pchar},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", multiply},
		{"div", divide},
		{"mod", modulate},
		{"rotl", rotl},
		{"rotr", rotr},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; instruction[i].opcode; i++)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
		{
			instruction[i].f(&(global.top), line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	clean();
	exit(EXIT_FAILURE);
}
