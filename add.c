#include "monty.h"

/**
 * fxn_add - returns addition of top 2 elements
 * @head: head
 * @ctr: no. of lines
 * Return: nothing
 */
void fxn_add(stack_t **head, unsigned int ctr)
{
	stack_t *h_ptr;
	int len = 0, mark;

	for (h_ptr = *head; h_ptr; h_ptr = h_ptr->next)
	{
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ctr);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h_ptr = *head;
	mark = h_ptr->n + h_ptr->next->n;
	h_ptr->next->n = mark;
	*head = h_ptr->next;
	free(h_ptr);
}
