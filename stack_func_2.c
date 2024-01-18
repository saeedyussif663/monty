#include "monty.h"

/**
  * pop_func - removes an object from the top of the stack
  * @stack: The stack
  * @line_num: Line number
  */

void pop_func(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	*stack = curr->next;

	if (*stack)
		(*stack)->prev = NULL;


	free(curr);
}


/**
  * nop_func - No opcode
  * @stack: Stack
  * @line_num: Line number
  */

void nop_func(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
