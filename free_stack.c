#include "monty.h"
/**
 * free_stack - Frees a list
 * @head: ptr to head
 */
void free_stack(stack_t *head)
{
	stack_t *mark;

	mark = head;
	while(head)
	{
		mark = head->next;
		free(head);
		head = mark;
	}
}
