#include "monty.h"
/**
 * fxn_pop - outputs top of a stack
 * @head: pointer to stacks head
 * @ctr: Number of lines
 * Return: no return
*/
void fxn_pop(stack_t **head, unsigned int ctr)
{
	stack_t *h_ptr;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ctr);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h_ptr = *head;
	*head = h_ptr->next;
	free(h_ptr);
}
