#include "sort.h"

/**
 * selection_sort - Code sorts an array
 *@size: array size
 * @array: number list
 */

void selection_sort(int *array, size_t size)
{
	size_t i, n;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		tmp = i;
		flag = 0;
		for (n = i + 1; n < size; n++)
		{
			if (array[tmp] > array[n])
			{
				tmp = n;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
