#include "lists.h"
/**
 * listint_len - list length
 * @l: struct to go through
 * Return: count
 */
size_t listint_len(const listint_t *l)
{
	size_t count = 0;

	while (l != NULL)
	{
		count++;
		l = l->next;
	}

	return (count);
}
