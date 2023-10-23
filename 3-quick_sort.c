#include "sort.h"

/**
 * swap - function swaps two int
 * @a: an integer
 * @b: an integer
 * Return: (void) Swaped intintegers
 */

void swap(int *a, int *b)
{
	int num;

	num = *a;
	*a = *b;
	*b = num;
}

/**
 * partition - Function partition san array
 * @array: The array
 * @low: an integer
 * @high: an integer
 * @size: the size of the array 
 * Return: index of pivoted
 */

int partition(int *array, int low, int high, size_t size)
{
	int piv = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= piv)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}

/**
 * lomuto_qsort - Function sorts array recursively
 * @array: an array to be sorted
 * @low: lowest value of the array
 * @high: highest value of the array
 * @size: the size of array
 * Return: void
 */

void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int n;

	if (low < high)
	{
		n = partition(array, low, high, size);
		lomuto_qsort(array, low, n - 1, size);
		lomuto_qsort(array, n + 1, high, size);
	}
}

/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */

void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
