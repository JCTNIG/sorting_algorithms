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
 * insertion_sort_list - sorts a doubly linked list of integers in
 *                       ascending order using the insertion sort algorithm
 * @list: double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *tmpr;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		tmp = curr;

		while (tmpr->prev != NULL && tmpr->n < tmpr->prev->n)
		{
			if (tmpr->next != NULL)
			{
				tmpr->next->prev = tmpr->prev;
			}

		tmpr->prev->next = tmpr->next;
		tmpr->next = tmpr->prev;
		tmpr->prev = tmpr->prev->prev;

		if (tmpr->prev == NULL)
		{
			(*list) = tmpr;
		}
		else
		{
			tmpr->prev->next = tmpr;
		}

		tmpr->next->prev = tmpr;
		print_list(*list);
		}
	}
}
