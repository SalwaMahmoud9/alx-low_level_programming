#include "lists.h"
/**
 * pop_listint - pop node
 * @head: list address
 * Return: value
 */
int pop_listint(listint_t **head)
{
	int value = 0;
	listint_t *tmp;

	if (*head == NULL)
		return (value);
	tmp = *head;
	value = tmp->n;
	free(*head);
	*head = tmp->next;

	return (value);
}
