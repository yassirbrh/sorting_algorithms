#include "sort.h"

/**
 * bubble_sort - Function
 *
 * Description: Sorts an array of integers in ascending order
 *              using the Bubble sort algorithm
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * Return: No return because it's a void function.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp, sorted = 0;

	if (array != NULL && size > 1)
	{
		while (sorted == 0)
		{
			sorted = 1;
			for (i = 1; i < size; i++)
			{
				if (array[i] < array[i - 1])
				{
					tmp = array[i - 1];
					array[i - 1] = array[i];
					array[i] = tmp;
					print_array(array, size);
					sorted = 0;
				}
			}
		}
	}
}
