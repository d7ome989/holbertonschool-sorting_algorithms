#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 *
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 *
 * @array: The array to partition
 * @size: Number of elements in @array
 * @low: Starting index of the partition
 * @high: Ending index of the partition, used as the pivot
 *
 * Return: Final index of the pivot
 */
size_t lomuto_partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				swap_ints(array + i, array + j);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > pivot)
	{
		swap_ints(array + i, array + high);
		print_array(array, size);
	}

	return (i);
}

/**
 * lomuto_sort - Recursively sorts an array using the Lomuto partition scheme
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void lomuto_sort(int *array, size_t size, size_t low, size_t high)
{
	size_t pivot;

	if (low >= high)
		return;

	pivot = lomuto_partition(array, size, low, high);

	if (pivot > low)
		lomuto_sort(array, size, low, pivot - 1);
	lomuto_sort(array, size, pivot + 1, high);
}

/**
 * quick_sort - Sorts an array of integers using Quick sort
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
