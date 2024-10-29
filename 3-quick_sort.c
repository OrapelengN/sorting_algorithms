#include "sort.h"
/* #include <stdio.h> */

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array using the Lomuto partition scheme.
 * @array: The array of integers.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array for printing.
 *
 * Return: The final pivot index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursion - Recursively applies quicksort to partitions.
 * @array: The array to sort.
 * @low: The starting index.
 * @high: The ending index.
 * @size: The size of the array.
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
