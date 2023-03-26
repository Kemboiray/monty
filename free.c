#include "monty.h"
#include <stdlib.h>

/**
* free_list - free stack
* @stack: pointer to stack
*
* Return: void.
*/
void free_list(stack_t *stack)
{
	stack_t *temp = stack;

	if (temp == NULL)
		return;
	while (temp)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
