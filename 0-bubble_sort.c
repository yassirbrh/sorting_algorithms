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
	size_t i, j;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j] <= array[j - 1])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
