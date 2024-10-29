#include <stdlib.h>
#include "deck.h"

/* Function to compare two cards */
int card_compare(const void *a, const void *b)
{
	const deck_node_t *card_a = *(const deck_node_t **)a;
	const deck_node_t *card_b = *(const deck_node_t **)b;

	/* Define card order values */
	const char *order_values[] = {
        "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "Jack", "Queen", "King"
	};

	/* Compare by kind first */
	if (card_a->card->kind != card_b->card->kind)
		return card_a->card->kind - card_b->card->kind;

	/* If kinds are equal, compare by value */
	for (int i = 0; i < 13; i++)
	{
		if (card_a->card->value == order_values[i])
			return -1; /* card_a comes before card_b */
		if (card_b->card->value == order_values[i])
			return 1;  /* card_b comes before card_a */
	}

	return 0; /* They are equal */
}

/* Function to sort the deck */
void sort_deck(deck_node_t **deck)
{
	deck_node_t **array;
	deck_node_t *current;
	size_t i, count = 0;

	/* Count the number of nodes in the deck */
	current = *deck;
	while (current)
	{
		count++;
		current = current->next;
	}

	/* Allocate memory for the array of nodes */
	array = malloc(sizeof(deck_node_t *) * count);
	if (!array)
		return;

	/* Populate the array with the deck nodes */
	current = *deck;
	for (i = 0; i < count; i++)
	{
		array[i] = current;
		current = current->next;
	}

	/* Sort the array using qsort */
	qsort(array, count, sizeof(deck_node_t *), card_compare);

	/* Rebuild the linked list from the sorted array */
	for (i = 0; i < count; i++)
	{
		array[i]->prev = (i > 0) ? array[i - 1] : NULL;
		array[i]->next = (i < count - 1) ? array[i + 1] : NULL;
	}

	/* Update the head of the deck */
	*deck = array[0];

	/* Free the array */
	free(array);
}
