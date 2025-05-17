#include <stdio.h>
#include "sort.h"

/**
* swap_ints - Swaps two integers in an array
* @a: Pointer to the first integer
* @b: Pointer to the second integer
*
* Description: This function swaps the values of two integers
*              by using a temporary variable.
*/
void swap_ints(int *a, int *b)
{
int tmp = *a;

*a = *b;
*b = tmp;
}

/**
* selection_sort - Sorts an array of integers in ascending order
*                  using the Selection sort algorithm.
* @array: Pointer to the array of integers to be sorted
* @size: The number of elements in the array
*/
void selection_sort(int *array, size_t size)
{
size_t i, j, min_idx;

if (!array || size < 2)
return;

for (i = 0; i < size - 1; i++)
{
min_idx = i; /* Assume current position is the minimum */

/* Find the smallest element in the unsorted part */
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_idx])
min_idx = j;
}

/* If the minimum is not at current position, swap and print */
if (min_idx != i)
{
swap_ints(&array[i], &array[min_idx]);
print_array(array, size);
}
}
}
