#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays
 * @array: Array to sort
 * @left: Left index
 * @mid: Middle index
 * @right: Right index
 */
void merge(int *array, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = malloc(n1 * sizeof(int));
	int *R = malloc(n2 * sizeof(int));

	if (!L || !R)
		return;

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];

	printf("Merging...\n[left]: ");
	for (i = 0; i < n1; i++)
		printf("%d%s", L[i], (i == n1 - 1) ? "\n" : ", ");

	printf("[right]: ");
	for (j = 0; j < n2; j++)
		printf("%d%s", R[j], (j == n2 - 1) ? "\n" : ", ");

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			array[k++] = L[i++];
		else
			array[k++] = R[j++];
	}

	while (i < n1)
		array[k++] = L[i++];

	while (j < n2)
		array[k++] = R[j++];

	printf("[Done]: ");
	for (i = left; i <= right; i++)
		printf("%d%s", array[i], (i == right) ? "\n" : ", ");

	free(L);
	free(R);
}

/**
 * merge_sort_helper - Recursive helper function for merge_sort
 * @array: Array to sort
 * @left: Left index
 * @right: Right index
 */
void merge_sort_helper(int *array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		merge_sort_helper(array, left, mid);
		merge_sort_helper(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers using merge sort
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_helper(array, 0, size - 1);
}
