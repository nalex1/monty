#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = global_id.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	if (global_id.data_struct == 1)
	{
		if (!node_add(stack, atoi(global_id.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!node_q(stack, atoi(global_id.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
