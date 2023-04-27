#include "sort.h"

/**
 * print_array_elmt - This funtion serves as the putchar for this project
 *
 * @elmt: function parameter
 * Returns: void function
 */

void print_array_elmt(int elmt)
{
	int numDigits = 0;
	int divider = 1;
	int digits;

	if (elmt == 0)
	{
		putchar('0');
		return;
	}

	while (elmt / divider != 0)
	{
		numDigits++;
		divider *= 10;
	}

	divider /= 10;
	while (divider != 0)
	{
		digits = elmt / divider;
		putchar(digits + '0');
		elmt -= digits * divider;
		divider /= 10;
	}
}

/**
 * part - this serves as apartition function
 * @array: array to be parted
 * @l: left index
 * @r: right index
 * Return: int value
 */

int part(int *array, int l, int r, size_t size)
{
	int pivot_index, imp, tmr, tmpr, swap, i;
	size_t j;
	/*int size = sizeof(array) / sizeof(int);*/

	pivot_index = r;
	pivot = array[r];
	swap = l - 1;

	for (i = l; i < pivot_index; i++)
	{
		if (array[i] < imp)
		{
			swap++;
			tmp = array[swap];
			array[swap] = array[i];
			array[i] = tmpr;
			for (j = 0; j < size; j++)
			{
				print_array_elmt(array[j]);
				if (j != size - 1)
				{
					putchar(',');
					putchar(' ');
				}
			}
		putchar('\n');
		}
	}
	tmr = array[swap + 1];
	array[swap + 1] = array[pivot_index];
	array[pivot_index] = tmr;
	return (swap + 1);
}

/**
 * quick_sort - This function sorts an array of size 'size',
 * using quick sort algo, in ascending order.
 *
 * @array: An array to be sorted
 * @size: size of the array
 * Return: void function
 */

void quick_sort(int *array, size_t size)
{
	int pivot_index;

	if (size <= 1)
	{
		return;
	}

	pivot_index = part(array, 0, size - 1, size);

	quick_sort(array, pivot_index);
	quick_sort(&array[pivot_index + 1], size - pivot_index - 1);
}
