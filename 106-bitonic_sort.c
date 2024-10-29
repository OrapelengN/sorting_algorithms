#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merges a bitonic sequence
 * @array: The array to sort
 * @low: The starting index of the sequence
 * @cnt: The count of elements in the sequence
 * @order: The order of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, int low, int cnt, int order)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		for (int i = low; i < low + k; i++)
		{
			if ((order == 1 && array[i] > array[i + k]) ||
				(order == 0 && array[i] < array[i + k]))
			{
				/* Swap */
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;

				/* Print after swapping */
				print_array(array, cnt + low);
			}
		}
		bitonic_merge(array, low, k, order);
		bitonic_merge(array, low + k, k, order);
	}
}

/**
 * bitonic_sort_recursive - Recursive function to perform bitonic sort
 * @array: The array to sort
 * @low: The starting index of the sequence
 * @cnt: The count of elements in the sequence
 * @order: The order of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, int low, int cnt, int order)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		/* Sort in ascending order */
		bitonic_sort_recursive(array, low, k, 1);
		/* Sort in descending order */
		bitonic_sort_recursive(array, low + k, k, 0);

		/* Merge the whole sequence */
		bitonic_merge(array, low, cnt, order);
	}
}

/**
 * bitonic_sort - Sorts an array of integers using the Bitonic sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	bitonic_sort_recursive(array, 0, size, 1);
}
