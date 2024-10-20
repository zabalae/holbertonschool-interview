#include "lists.h"

/**
 * check_cycle - determines if a singly linked list contains a cycle
 * @list: single pointer to the head of the list to check if cyclical
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *tortoise = NULL, *hare = NULL;

	if (list == NULL || list->next == NULL)
		return (0);
	tortoise = list;
	hare = list->next;
	while (hare && hare->next)
	{
		if (tortoise == hare)
			return (1);
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	if (hare && tortoise == hare)
		return (1);
	return (0);
}
