#include "lists.h"
/**
 * add_nodeint - add node
 * @head: start node
 * @n: new node
 * Return: head
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;

	*head = new;

	return (*head);
}
