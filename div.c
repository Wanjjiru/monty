#include "monty.h"
/**
 * fxn_div - gets div of top 2 elements
 * @head: head
 * @ctr: No. of lines
 * Return: nothing
*/
void fxn_div(stack_t **head, unsigned int ctr)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", ctr);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_ptr = *head;
	if (h_ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ctr);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	mark = h_ptr->next->n / h_ptr->n;
	h_ptr->next->n = mark;
	*head = h_ptr->next;
	free(h_ptr);
}
