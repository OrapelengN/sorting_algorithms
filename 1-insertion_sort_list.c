#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_node;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		current = current->next;
		while (temp->prev && temp->n < temp->prev->n)
		{
			prev_node = temp->prev;

			/* Swapping nodes */
			if (prev_node->prev)
				prev_node->prev->next = temp;
			temp->prev = prev_node->prev;

			prev_node->prev = temp;
			prev_node->next = temp->next;

			if (temp->next)
				temp->next->prev = prev_node;
			temp->next = prev_node;

			/* Update the head if necessary */
			if (!temp->prev)
				*list = temp;

			/* Print list after each swap */
			print_list(*list);
		}
	}
}
