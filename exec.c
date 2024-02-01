#include "monty.h"
/**
* execute - executes fxn
* @stack: linked list
* @ctr: No. of lines
* @file: poiner to monty file
* @cnct: content of a line
* Return: nothing
*/
int execute(char *cnct, stack_t **stack, unsigned int ctr, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int x = 0;
	char *opcod;

	opcod = strtok(cnct, " \n\t");
	if (opcod && opcod[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[x].opcode && opcod)
	{
		if (strcmp(opcod, opst[x].opcode) == 0)
		{	opst[x].f(stack, ctr);
			return (0);
		}
		x++;
	}
	if (opcod && opst[x].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", ctr, opcod);
		fclose(file);
		free(cnct);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
