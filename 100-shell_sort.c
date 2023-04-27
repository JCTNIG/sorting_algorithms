#include "sort.h"

/**
 * swap_ints - Function Swaping two integers in an array.
 * @a: integer to be swaped.
 * @b: integer to be swaped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts arrays of integers in ascending
 *              order with shell sorting algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: The Knuth interval sequence for sorting.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, s, f;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (s = gap; s < size; s++)
		{
			f = s;
			while (f >= gap && array[f - gap] > array[f])
			{
				swap_ints(array + f, array + (f - gap));
				f -= gap;
			}
		}
		print_array(array, size);
	}
}
