#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max = 0;
	int *count = NULL, *output = NULL;

	if (!array || size < 2)
		return;

	/* Find the maximum element in the array */
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Allocate memory for the counting array */
	count = malloc((max + 1) * sizeof(int));
	if (!count)
		return;

	/* Initialize and count occurrences of each number */
	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (size_t i = 0; i < size; i++)
		count[array[i]]++;

	/* Print the counting array */
	print_array(count, max + 1);

	/* Accumulate counts */
	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* Allocate memory for the output array */
	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}

	/* Build the sorted output array */
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy sorted elements back to the original array */
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	/* Free allocated memory */
	free(count);
	free(output);
}
