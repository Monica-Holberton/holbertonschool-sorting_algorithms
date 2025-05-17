#include "sort.h"
#include <stdio.h>

/**
* bubble_sort - Sorts an array of integers in ascending order
*               using the Bubble sort algorithm.
* @array: Sorted Array
* @size: Size of the Array
*/

void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;
int swap;

for (i = 0; i < size - 1; i++)
{
swap = 0;
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
/* Swap the elements */
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;

/* Print the array after each swap */
print_array(array, size);
swap = 1;
}
}

/* If no two elements were swapped by inner loop, break */
if (swap == 0)
break;
}
}
