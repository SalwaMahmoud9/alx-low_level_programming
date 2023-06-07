#include "lists.h"
#include <stdlib.h>

/**
 * reverse_recur -  list
 * @first: node to reverse
 * @second: node after node to reverse
 * Return: ptr
 */
listint_t *reverse_recur(listint_t *first, listint_t *second)
{
	listint_t *ptr, *prev = NULL;

	ptr = first;
	while (ptr->next != second)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	if (prev != NULL)
		prev->next = first;
	second = first->next;
	first->next = ptr->next;
	if (first != ptr && second != first)
		second = reverse_recur(second, first);
	ptr->next = second;
	return (ptr);
}

/**
 * reverse_listint - reverse list
 * @head: lhead
 * Return: head
 */
listint_t *reverse_listint(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (NULL);

	*head = reverse_recur(*head, NULL);
	return (*head);
}
