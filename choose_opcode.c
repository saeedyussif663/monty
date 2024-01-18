#include "monty.h"

/**
  * choose_opcode - Selects the right opcode
  * @tokens: Token array
  * @stack: The pointer
  * @line_number: Line number
  * Return: 0 on success, 1 otherwise
  */

int choose_opcode(char **tokens, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"pall", pall_func},
		{"pint", pint_func},
		{"nop", nop_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{NULL, NULL}
	};

	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(tokens[0], instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (0);
		}
	}

	return (1);
}
