#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Sifts down the node at index `i` to maintain the heap property
 * @array: The array representing the heap
 * @size: The size of the array
 * @i: The index of the node to sift down
 */
void sift_down(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		printf("Swap: %d <-> %d\n", array[largest], array[i]);
		print_array(array, size);
		sift_down(array, size, largest);
	}
}

/**
 * heapify - Builds a max heap from an array
 * @array: The array to heapify
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i);
}

/**
 * heap_sort - Sorts an array of integers using heap sort
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	heapify(array, size);

	for (size_t i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		printf("Swap: %d <-> %d\n", array[i], array[0]);
		print_array(array, size);
		sift_down(array, i, 0);
	}
}
