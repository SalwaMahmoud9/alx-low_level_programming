#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_skiplist - free_skiplistt
 *
 * @list: list
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_skiplist(node);
	}
}
