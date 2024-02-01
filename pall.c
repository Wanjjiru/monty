#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: head
 * @ctr: no. of line
 * Return: nothing
*/
void f_pall(stack_t **head, unsigned int ctr)
{
	stack_t *h_ptr;
	(void)ctr;

	h_ptr = *head;
	if (h_ptr == NULL)
		return;
	while (h_ptr)
	{
		printf("%d\n", h_ptr->n);
		h_ptr = h_ptr->next;
	}
}
