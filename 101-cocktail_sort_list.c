#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @left: Pointer to the left node to swap.
 * @right: Pointer to the right node to swap.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
	*list = right;

	if (right->next)
	right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;

	print_list(*list);
}

/**
 * forward_pass - Performs a forward pass of cocktail shaker sort.
 * @list: Double pointer to the head of the doubly linked list.
 * @swapped: Pointer to the swapped flag.
 */
void forward_pass(listint_t **list, int *swapped)
{
	listint_t *current = *list;

	while (current->next)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			*swapped = 1;
		}
		else
			current = current->next;
	}
}

/**
 * backward_pass - Performs a backward pass of cocktail shaker sort.
 * @list: Double pointer to the head of the doubly linked list.
 * @swapped: Pointer to the swapped flag.
 */
void backward_pass(listint_t **list, int *swapped)
{
	listint_t *current = *list;

	while (current->next)
		current = current->next;

	while (current->prev)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			*swapped = 1;
		}
		else
			current = current->prev;
	}
}

/**
 * cocktail_sort_list - Sort doubly linked list using the Cocktail shaker sort.
 * @list: Double pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		forward_pass(list, &swapped);
		if (!swapped)
			break;
		swapped = 0;
		backward_pass(list, &swapped);
	}
}
