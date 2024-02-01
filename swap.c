#include "monty.h"
/**
 * fxn_swap - moves 2 elements of a stack.
 * @head: ptr to head
 * @ctr: no. of line
 * Return: nothing
*/
void fxn_swap(stack_t **head, unsigned int ctr)
{
	stack_t *h_ptr;
	int len = 0, mark;

	h_ptr = *head;
	while (h_ptr)
	{
		h_ptr = h_ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ctr);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_ptr = *head;
	mark = h_ptr->n;
	h_ptr->n = h_ptr->next->n;
	h_ptr->next->n = mark;
}
