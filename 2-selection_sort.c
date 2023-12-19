#include "sort.h"

/**
 * int_swap - Swaps two integers in an array.
 * @m: The first integer to swap.
 * @n: The second integer to swap.
 */
void int_swap(int *m, int *n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t r, s;

	if (array == NULL || size < 2)
		return;

	for (r = 0; r < size - 1; r++)
	{
		min = array + r;
		for (s = r + 1; s < size; s++)
			min = (array[s] < *min) ? (array + s) : min;

		if ((array + r) != min)
		{
			int_swap(array + r, min);
			print_array(array, size);
		}
	}
}
