#include "sort.h"

/**
 * swap_handler - swap two ints
 * @i: first int
 * @j: second int
 */
void swap_handler(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * selection_sort - selection sort on array
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap_handler(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
