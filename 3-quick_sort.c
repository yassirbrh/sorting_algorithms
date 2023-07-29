#include "sort.h"

/**
 * swap_numbers - Function
 *
 * Description: Swap two integers in an array.
 *
 * @firstNum: The first integer to swap.
 * @secondNum: The second integer to swap.
 */
void swap_numbers(int *firstNum, int *secondNum)
{
	int tmp;

	tmp = *firstNum;
	*firstNum = *secondNum;
	*secondNum = tmp;
}

/**
 * lomuto_partition - Function
 *
 * Description: Sort the array using the lomuto partition scheme.
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The first index of the subarray.
 * @right: The last index of the subarray.
 *
 * Return: index of the above index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, below, above;

	pivot = array + right;
	above = left;
	for (below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (below > above)
			{
				swap_numbers(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_numbers(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - Function
 *
 * Description: sorting the array using quicksort algorithm through recursion.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 * @left: The first index of the subarray.
 * @right: The last index of the subarray.
 *
 * Return: No return because it's a void function
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int index;

	if (right - left > 0)
	{
		index = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, index - 1);
		lomuto_sort(array, size, index + 1, right);
	}
}

/**
 * quick_sort - Function
 *
 * Description: Sort an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: No return because it's a void function.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		lomuto_sort(array, size, 0, size - 1);
}
