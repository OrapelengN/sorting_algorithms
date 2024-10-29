#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the maximum value in an array
 * @array: The array to search
 * @size: The size of the array
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Helper function to perform counting sort based on the digit
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The current digit's place value (1, 10, 100, etc.)
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	/* Count occurrences of each digit */
	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Update count[i] to be the position of this digit in output */
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array to the original array */
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using the Radix sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Get the maximum number to know the number of digits */
	int max = get_max(array, size);

	/* Do counting sort for every digit */
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		/* Print the array after sorting by each digit */
		print_array(array, size);
	}
}
