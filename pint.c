#include "monty.h"
/**
 * fxn_pint - prints top line
 * @head: head
 * @ctr: No. of line
 * Return: nothing
*/
void fxn_pint(stack_t **head, unsigned int ctr)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ctr);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
