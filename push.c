#include "monty.h"
/**
 * fxn_push - pushes a node to stack
 * @head: head
 * @ctr: No. of lines
 * Return: nothing
*/
void fxn_push(stack_t **head, unsigned int ctr)
{
	int x, y = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			y++;
		for (; bus.arg[y] != '\0'; y++)
		{
			if (bus.arg[y] > 57 || bus.arg[y] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", ctr);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", ctr);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	x = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(head, x);
	else
		add_queue(head, x);
}
