#include <stdio.h>

/**
 * print_array - Prints an array of integers.
 * @array: Array to be printed.
 * @size: Size of the array.
 */

void print_array(int *array, size_t size)
{
size_t i;
for (i = 0; i < size; i++)
{
printf("%d", array[i]);
if (i < size - 1)
printf(", ");
}
printf("\n");
}
