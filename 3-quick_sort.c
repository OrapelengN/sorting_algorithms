#include "sort.h"
#include <stdio.h>

/* Function to swap two elements in an array */
/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Array after swap: ");
	print_array(a, b - a + 1);  /* Print the current state of the array */
}

/* Lomuto partition scheme */

/**
 * partition - Partitions the array using the Lomuto partition scheme.
 * The pivot is chosen as the last element, and the function rearranges
 * the array such that elements less than the pivot are on the left,
 * and elements greater than the pivot are on the right.
 * @array: The array of integers to be sorted.
 * @size: The total size of the array.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 *
 * Return: The partition index.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];  /* Last element as pivot */
	int i = low - 1;          /* Index of smaller element */
	int j; /* Declare j outside of the loop */

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				/* Swap if element is smaller than pivot */
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		/* Place the pivot in the correct position */
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);  /* Return the partitioning index */
}

/* Recursive Quick Sort function */

/**
 * quick_sort_recursion - Recursively sorts partitions of the array
 * using the Quick sort algorithm and Lomuto partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The total size of the array.
 * @low: The starting index of the current partition.
 * @high: The ending index of the current partition.
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		/* Partitioning index */
		int pi = partition(array, size, low, high);
		/* Recursively sort left part */
		quick_sort_recursion(array, size, low, pi - 1);
		/* Recursively sort right part */
		quick_sort_recursion(array, size, pi + 1, high);
	}
}

/* Main Quick Sort function */
/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * Quick sort algorithm with the Lomuto partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursion(array, size, 0, size - 1);
}
