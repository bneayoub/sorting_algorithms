#include "sort.h"
/**
 * swaper - swapes
 * @a: arg
 * @b: arg
 */
void swaper(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - selection----
 * @array: arg
 * @size: arg
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			swaper(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
