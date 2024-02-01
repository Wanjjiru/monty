#include "monty.h"
/**
  * fxn_sub- difference of first 2 elements
  * @head: head
  * @ctr: no. of line
  * Return: nothing
 */
void fxn_sub(stack_t **head, unsigned int ctr)
{
	stack_t *mark;
	int x, nodes;

	mark = *head;
	for (nodes = 0; mark != NULL; nodes++)
		mark = mark->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ctr);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	mark = *head;
	x = mark->next->n - mark->n;
	mark->next->n = x;
	*head = mark->next;
	free(mark);
}
