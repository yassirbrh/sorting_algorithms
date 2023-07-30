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
 * swap_array_of_two - Function
 *
 * Description: Swaps the two elements if the order is decreasing in the array
 *
 * @array: Pointer to the array.
 * @sizeOfArr: Size of the array.
 *
 * Return: No return because it's a void function.
 */
void swap_array_of_two(int *array, size_t sizeOfArr)
{
	printf("Merging...\n[left]: %d\n[right]: %d\n", array[0], array[1]);
	if (array[0] > array[1])
		swap_numbers(array, array + 1);
	printf("[Done]: ");
	print_array(array, sizeOfArr + 1);
}
/**
 * merge_sort - Function
 *
 * Description: Sorts an array in ascending way using the merge sort algorithm
 *
 * @array: Pointer to the array of integers
 * @size: Size of the array of integers.
 *
 * Return: No return because it's a void function.
 */
void merge_sort(int *array, size_t size)
{
	size_t sizeOfArr = size / 2, i, j = sizeOfArr;

	if (size > 2)
	{
		merge_sort(array, sizeOfArr);
		if (size % 2 == 0)
			merge_sort(array + sizeOfArr, sizeOfArr);
		else
		{
			merge_sort(array + sizeOfArr + 1, sizeOfArr);
			printf("Merging...\n[left]: %d\n[right]: ", array[sizeOfArr]);
			print_array(array + sizeOfArr + 1, sizeOfArr);
			for (i = j + 1; i < size; i++)
			{
				if (array[i] < array[j])
				{
					swap_numbers(array + i, array + j);
					j = i;
				}
			}
			printf("[Done]: ");
			print_array(array + sizeOfArr, sizeOfArr + 1);
		}
		printf("Merging...\n[left]: ");
		print_array(array, sizeOfArr);
		printf("[right]: ");
		print_array(array + sizeOfArr, size - sizeOfArr);
		for (i = 0; i < sizeOfArr; i++)
		{
			for (j = size - 1; j >= sizeOfArr; j--)
			{
				if (array[i] > array[j])
					swap_numbers(array + i, array + j);
			}
		}
		printf("[Done]: ");
		print_array(array, size);
	}
	else
		swap_array_of_two(array, sizeOfArr);
}
