#include "lists.h"

/**
 * get_dnodeint_at_index - get_dnodeint_at_index
 * @head: head
 * @index: index
 *
 * Return: head
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
