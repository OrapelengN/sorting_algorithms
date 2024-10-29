#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: The array of integers to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Handle cases where no sorting is needed */
	if (array == NULL || size < 2)
		return;

	/* Generate the maximum Knuth sequence gap less than size */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Shell sort using Knuth sequence */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size); /* Print array after each gap decrement */
		gap = (gap - 1) / 3;
	}
}
