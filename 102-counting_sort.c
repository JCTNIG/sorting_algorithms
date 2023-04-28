#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int a, largest;

	for (largest = array[0], a = 1; a < size; a++)
	{
		if (array[a] > largest)
			largest = array[a];
	}

	return (largest);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, a, largest;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	largest = get_max(array, size);
	count = malloc(sizeof(int) * (largest + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (a = 0; a < (largest + 1); a++)
		count[a] = 0;
	for (a = 0; a < (int)size; a++)
		count[array[a]] += 1;
	for (a = 0; a < (largest + 1); a++)
		count[a] += count[a - 1];
	print_array(count, largest + 1);

	for (a = 0; a < (int)size; a++)
	{
		sorted[count[array[a]] - 1] = array[a];
		count[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = sorted[a];

	free(sorted);
	free(count);
}
