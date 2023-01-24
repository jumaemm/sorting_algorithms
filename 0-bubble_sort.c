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
 * bubble_sort - sort an array of ints
 * @array: array of ints to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_handler(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}

}
