#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

global_t global = {0, NULL, NULL, NULL, NULL};
/**
 * main - entry point
 * @argc: argument count
 * @argv: pointer to argument array
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	unsigned int line_number = 1;
	ssize_t nread;
	char *opcode = NULL;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	global.file = fopen(argv[1], "r");
	if (!(global.file))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&(global.line), &len, global.file)) != -1)
	{
		if (strspn(global.line, " \n\r\t\a") == strlen(global.line))
		{
			line_number++;
			continue;
		}
		opcode = strtok(global.line, " \n\t");
		if (opcode[0] == '#')
		{
			line_number++;
			continue;
		}
		global.arg = opcode + strlen(opcode) + 1;
		execute(opcode, line_number);
		line_number++;
	}
	clean();
	exit(EXIT_SUCCESS);
}
