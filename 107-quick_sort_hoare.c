#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in the array
 * @array: The array containing the elements
 * @i: The index of the first element
 * @j: The index of the second element
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
	print_array(array, (size_t)sizeof(array) / sizeof(array[0]));
}

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme
 * @array: The array to partition
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(array, i, j);
	}
}

/**
 * quick_sort_recursive - Recursively applies Quick Sort
 * @array: The array to sort
 * @low: The starting index of the sorting range
 * @high: The ending index of the sorting range
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high);

		quick_sort_recursive(array, low, pivot_index);
		quick_sort_recursive(array, pivot_index + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1);
}
