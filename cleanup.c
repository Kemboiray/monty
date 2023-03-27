#include "monty.h"
#include <stdlib.h>

/**
 * clean - free allocated memory and close file
 *
 * Return: void.
 */
void clean(void)
{
	free_list(global.top);
	free(global.line);
	fclose(global.file);
}
