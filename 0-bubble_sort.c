#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using Bubble sort
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, s2 = size;
	int t, s;

	for (i = 0; i < size; i++)
	{
		s = 0;
		for (j = 0; j < s2; j++)
		{
			if (array[j - 1] > array[j])
			{
				s = 1;
				t = array[j];
				array[j] = array[j - 1];
				array[j - 1] = t;
				print_array(array, size);
			}
		}
		if (s == 0)
			break;
		s = 0;
		s2--;
	}
}
