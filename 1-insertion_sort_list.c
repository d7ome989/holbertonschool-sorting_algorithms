#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *prev;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			if (current->next != NULL)
				current->next->prev = prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			current->prev = prev->prev;
			prev->next = current->next;
			current->next = prev;
			prev->prev = current;

			print_list(*list);

			prev = current->prev;
		}

		current = next;
	}
}
