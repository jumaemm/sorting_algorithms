#include "sort.h"

/**
 * swap_handler - handle the swap operation of the ints
 * @i: first int
 * @j: second int
 */
void swap_handler(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * partition - partition the array around the pivot
 * @array: array to be partitioned
 * @size: size of the array
 * @low: low pointer
 * @high: high pointer
 * Return: partition index
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot, right, left;

	pivot = array + high;
	for (right = left = low; left < high; left++)
	{
		if (array[left] < *pivot)
		{
			if (right < left)
			{
				swap_handler(array + left, array + right);
				print_array(array, size);
			}
			right++;
		}
	}

	if (array[right] > *pivot)
	{
		swap_handler(array + right, pivot);
		print_array(array, size);
	}

	return (right);
}

/**
 * quick_sort_helper - recursive quick sort implementation
 * @array: array to sort
 * @size: size of the array
 * @low: low pointer
 * @high: high pointer
 */
void quick_sort_helper(int *array, size_t size, int low, int high)
{
	int pIndex;

	if (low < high)
	{
		pIndex = partition(array, size, low, high);

		quick_sort_helper(array, size, low, pIndex - 1);
		quick_sort_helper(array, size, pIndex + 1, high);
	}
}

/**
 * quick_sort - quick sort implementation
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, size, 0, size - 1);
}
