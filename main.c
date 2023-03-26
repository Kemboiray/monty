#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 * @argc: argument count
 * @argv: pointer to argument array
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	char line_cpy[LINE_LENGTH];
	size_t len = 0, line_number = 1;
	ssize_t nread;
	static char *tokens[] = {NULL, NULL};
	stack_t *top = NULL;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	memset(line_cpy, 0, LINE_LENGTH);

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, file)) != -1)
	{
		if (strspn(line, " \n\r\t\a") == strlen(line))
		{
			free(line);
			line = NULL;
			continue;
		}
		strncpy(line_cpy, line, LINE_LENGTH);
		tokens[0] = strtok(line_cpy, " \n\t");
		tokens[1] = &line_cpy[strlen(tokens[0]) + 1];
		free(line);
		line = NULL;
		top = execute(tokens, line_number);
		line_number++;
	}
	free_list(top), free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
