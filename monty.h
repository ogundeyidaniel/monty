#ifndef _MONTY_H
#define _MONTY_H

/* Libraries */
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct instance_s - data instance
 * @line: the readed line
 * @args: the arguments
 * @line_number: line number
 * @fp: the file
 * @filename: filename
 * Description: data instance, line, args
 */
typedef struct instance_s
{
	char *line;
	char **args;
	char *filename;
	int line_number;
	FILE *fp;
} data_t;

extern data_t data;

/* Prototypes */
int process_line(stack_t **stack);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void add_dnodeint(stack_t **stack, unsigned int line_number);
void push_error(short int err_code);
void free_data(void);
void print_dlistint(stack_t **stack, unsigned int line_number);
void free_dlistint(stack_t *stack);
int split_line(void);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void swap_top(stack_t **stack, unsigned int line_number);
int _isdigit(char *str);
void nothing(stack_t **stack, unsigned int line_number);
void add_top_two(stack_t **stack, unsigned int line_number);
void sub_top_two(stack_t **stack, unsigned int line_number);
void div_top_two(stack_t **stack, unsigned int line_number);
void mul_top_two(stack_t **stack, unsigned int line_number);
void mod_top_two(stack_t **stack, unsigned int line_number);
extern global_var var_global;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);

/*Fuxntions Monty*/
void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

/*Functions string ascci */
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);

/*Functions math*/
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/*Utility functions*/
void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);

#endif /* _MONTY_H */
