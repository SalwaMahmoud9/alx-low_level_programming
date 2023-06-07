#include "lists.h"
/**
 * free_listint - free list
 * @head: head
 */
void free_listint(listint_t *head)
{
	listint_t *next;

	if (head == NULL)
		return;

	for (next = head->next; head != NULL; head = next)
	{
		next = head->next;
		free(head);
	}

}
