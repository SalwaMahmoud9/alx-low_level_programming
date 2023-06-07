#include "lists.h"
/**
 * print_listint - print list
 * @l: list
 * Return: count
 */
size_t print_listint(const listint_t *l)
{
	size_t count = 0;

	while (l != NULL)
	{
		printf("%d\n", l->n);
		count++;
		l = l->next;
	}

	return (count);
}
