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
				{"push", fxn_push}, {"pall", fxn_pall}, {"pint", fxn_pint},
				{"pop", fxn_pop},
				{"swap", fxn_swap},
				{"add", fxn_add},
				{"nop", fxn_nop},
				{"sub", fxn_sub},
				{"div", fxn_div},
				{"mul", fxn_mul},
				{"mod", fxn_mod},
				{"stack", fxn_stack},
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
