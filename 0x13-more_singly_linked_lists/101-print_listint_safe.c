#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * find_listint_loop_pl - finds a loop
 * @head: list
 * Return: address of node or NULL
 */
listint_t *find_listint_loop_pl(listint_t *head)
{
	listint_t *ptr, *end;

	if (head == NULL)
		return (NULL);

	for (end = head->next; end != NULL; end = end->next)
	{
		if (end == end->next)
			return (end);
		for (ptr = head; ptr != end; ptr = ptr->next)
			if (ptr == end->next)
				return (end->next);
	}
	return (NULL);
}

/**
 * print_listint_safe - print list
 * @head: head
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t len = 0;
	int loop;
	listint_t *loopnode;

	loopnode = find_listint_loop_pl((listint_t *) head);

	for (len = 0, loop = 1; (head != loopnode || loop) && head != NULL; len++)
	{
		printf("[%p] %d\n", (void *) head, head->n);
		if (head == loopnode)
			loop = 0;
		head = head->next;
	}

	if (loopnode != NULL)
		printf("-> [%p] %d\n", (void *) head, head->n);
	return (len);
}
