#include "sort.h"

/**
 * print_array_elmt - This funtion serves as the putchar for this project
 *
 * @elmt: function parameter
 * Returns: void function
 */

void print_array_elmt(int elmt)
{
	int numDigit = 0;
	int divider = 1;
	int digits;

	if (elmt == 0)
	{
		putchar('0');
		return;
	}

	while (elmt / divider != 0)
	{
		numDigit++;
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
 * bubble_sort - This function sorts an array of size 'size'
 * in ascending order
 *
 * @array: An array to be sorted
 * @size: size of the array
 * Return: void function
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b, c;

	if (size < 2)
	{
		return;
	}
	else
	{

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				for (c = 0; c < size; c++)
				{
					print_array_elmt(array[c]);
					if (c != size - 1)
					{
						putchar(',');
						putchar(' ');
					}
				}
				putchar('\n');
			}
		}
	}
}
}
