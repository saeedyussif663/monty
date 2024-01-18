#include "monty.h"

/**
  * free_stack - free the stack
  * @stack: Stack
  */

void free_stack(stack_t **stack)
{
	stack_t *curr;

	while (*stack)
	{
		curr = *stack;
		*stack = (*stack)->next;
		free(curr);
	}
}

/**
  * push_func - Function to add items
  * @stack: Stack
  * @line_num: Line number
  * @val: Value
  */

void push_func(stack_t **stack, unsigned int line_num, int val)
{
	int mode = 0;
	stack_t *curr;
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_num;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	new_node->prev = NULL;
	if (mode == 0)
	{
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		curr = *stack;
		if (curr)
		{
			while (curr->next)
				curr = curr->next;
			curr->next = new_node;
			new_node->next = NULL;
			new_node->prev = curr;
		}
		else
		{
			*stack = new_node;
			new_node->next = NULL;
		}
	}
}

/**
  * pall_func - Function to print stack items
  * @line_num: Line number
  * @stack: The current stack
  */

void pall_func(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = *stack;

	(void)line_num;

	if (*stack == NULL)
		return;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
  * pint_func - Prints the value at the top
  * @stack: the pointer
  * @line_num: line number
  */

void pint_func(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = *stack;

	if (*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	if (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
  * swap_func - Function to swap two elements
  * @stack: Stack
  * @line_num: Line number
  */

void swap_func(stack_t **stack, unsigned int line_num)
{
	int n1, n2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	n1 = (*stack)->n;
	n2 = (*stack)->next->n;

	(*stack)->n = n2;
	(*stack)->next->n = n1;
}
