#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>

/* STRUCT DEFINITIONS */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variable
 * @item: integer to push to stack
 * @arg: argument string to push()
 * @line: pointer to line buffer
 * @top: pointer to stack
 * @file: pointer to file stream
 *
 * Description: global variable
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_s
{
	int item;
	char *arg;
	char *line;
	stack_t *top;
	FILE *file;
} global_t;

extern global_t global;
/* FUNCTION DECLARATIONS */
void execute(char *opcode, unsigned int line_number);
unsigned int is_number(char *str);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void modulate(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_list(stack_t *stack);
void clean(void);

#endif /* MONTY_H */
