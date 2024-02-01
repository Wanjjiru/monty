#include "monty.h"

/**
 * f_mod - gets modulus of stacks top element
 * @head: head
 * @ctr: no. of line
 * Return: nothing
*/
void f_mod(stack_t **head, unsigned int ctr)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", ctr);
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
	mark = h_ptr->next->n % h_ptr->n;
	h_ptr->next->n = mark;
	*head = h_ptr->next;
	free(h_ptr);
}
