#include "sort.h"

/**
 * swap_numbers - Function
 *
 * Description: Swaps two integers in the array.
 *
 * @num1: First number.
 * @num2: Second number.
 *
 * Return: No return because it's a void function.
 */
void swap_numbers(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
/**
 * shell_sort - Function
 *
 * Description: Sorts an array of integers in ascending order using the Shell
 *              sort algorithm, using the knuth sequence.
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array of integers.
 *
 * Return: No return because it's a void function.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array != NULL && size > 1)
	{
		for (i = 1; i < (size - 1) / 3; i = (i * 3) + 1)
		;
		gap = i;
		while (gap >= 1)
		{
			for (i = gap; i < size; i++)
			{
				j = i;
				while (j >= gap && (array[j - gap] > array[j]))
				{
					swap_numbers(array + (j - gap), array + j);
					j -= gap;
				}
			}
			gap = (gap - 1) / 3;
			print_array(array, size);
		}
	}
}
