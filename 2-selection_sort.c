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
 * selection_sort - Function
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * Return: No return because it's a void function.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	for (i = 0; i < size; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
				min = array + j;
		}
		if (min != array + i)
		{
			swap_numbers(array + i, min);
			print_array(array, size);
		}
	}
}
