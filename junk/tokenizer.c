//#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenize - tokenize a string
 * @str: string
 *
 * Return: array of tokens.
 */
char **tokenize(char *str)
{
	char *token = NULL;
	static char *ret[] = {NULL, NULL, NULL, NULL};
	int i = 0;

	token = strtok(str, " \t");

	while (token && i < 2)
	{
		ret[i] = malloc(strlen(token) + 1);
		if (!(ret[i]))
		{
			for (int j = 0; j <= i; j++)
				free(ret[j]);
			return (NULL);
		}

		strcpy(ret[i], token);
		token = strtok(NULL, " \t");
		i++;
	}

	return (ret);
}
