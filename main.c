#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void error_file(char *argv);
void error_usage(void);
int status = 0;		/* global_id var declaration */

/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: amount of args
 *
 * Return: nothing
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_counter = 1;

	global_id.data_struct = 1;  /* struct defined in monty.h L58*/
	if (argc != 2)
		error_usage(); /* def in line 82 */

	file = fopen(argv[1], "r");

	if (!file)
		error_file(argv[1]);  /* def in line 68 */

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_counter++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_counter++;
			continue;
		}
		global_id.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_counter);
		line_counter++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * error_file - prints file error message and exits
 * @argv: argv given by main()
 *
 * Desc: print msg if  not possible to open the file
 * Return: nothing
 */
void error_file(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - prints usage message and exits
 *
 * Desc: if user does not give any file or more than
 * one argument to your program
 *
 * Return: nothing
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
