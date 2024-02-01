#include "monty.h"
/**
 * f_queue - prints the top
 * @head: head
 * @ctr: no. of line
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int ctr)
{
	(void)head;
	(void)ctr;
	bus.lifi = 1;
}

/**
 * add_queue - add node at stack end
 * @n: new_value
 * @head: head
 * Return: nothing
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new, *mark;

	mark = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (mark)
	{
		while (mark->next)
			mark = mark->next;
	}
	if (!mark)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		mark->next = new;
		new->prev = mark;
	}
}
