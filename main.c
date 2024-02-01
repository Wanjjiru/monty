#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>

bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: no. of arguments
* @argv: location of monty file
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *cnct;
	FILE *file;
	size_t size = 0;
	ssize_t see_line = 1;
	stack_t *stack = NULL;
	unsigned int ctr = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (see_line > 0)
	{
		cnct = NULL;
		see_line = getline(&cnct, &size, file);
		bus.content = cnct;
		ctr++;
		if (see_line > 0)
		{
			execute(cnct, &stack, ctr, file);
		}
		free(cnct);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
