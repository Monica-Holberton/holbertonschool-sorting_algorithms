#include <stdio.h>
#include "sort.h"

/**
* swap_ints - Swaps two integers in an array
* @a: Pointer to the first integer
* @b: Pointer to the second integer
*
* Description: Swaps the values of a and b using a temporary variable.
*/
void swap_ints(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}

/**
* lomuto_partition - Partitions the array using Lomuto scheme
* @array: The array to be partitioned
* @low: The starting index of the partition
* @high: The ending index (pivot)
* @size: Size of the array (for printing)
*
* Return: The final index of the pivot element after partition
*
* Description: The pivot is the last element. All smaller elements
*              go to the left, larger to the right. Swaps are printed.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
swap_ints(&array[i], &array[j]);
print_array(array, size);
}
}
}

if (i + 1 != high)
{
swap_ints(&array[i + 1], &array[high]);
print_array(array, size);
}

return (i + 1);
}

/**
* quick_sort_recursive - Recursively sorts subarrays using Quick sort
* @array: Array to sort
* @low: Starting index of the current subarray
* @high: Ending index of the current subarray
* @size: Size of the array (for printing)
*
* Description: Applies recursive Quick sort on subarrays.
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int pivot_index;

if (low < high)
{
pivot_index = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers using the Quick sort algorithm
* @array: Array to sort
* @size: Size of the array
*
* Description: This function checks input validity and starts the recursive
*              sorting process using the Lomuto partition scheme.
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
