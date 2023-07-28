#include "sort.h"

/**
* swaper - swap
* @arr: array
* @i: index
* @j: index
**/
void swaper(int *arr, size_t i, size_t j)
{
	int tmp = arr[i];

	arr[i] = arr[j];
	arr[j] = tmp;
}

/**
 * swapAndPrint - Swaps two elements in an array and prints it
 * @array: Pointer to the array.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 * @arraySize: Size of the array.
 * Return : void
 */
void swapAndPrint(int *array, size_t i, size_t j, size_t arraySize)
{
	if (i != j)
	{
		swaper(array, i, j);
		print_array(array, arraySize);
	}
}

/**
 * partitionArray - Partitions an array around a pivot element.
 * @array: Pointer to the array to be partitioned.
 * @startIdx: Starting index of the subarray to be partitioned.
 * @endIdx: Ending index of the subarray to be partitioned.
 * @arraySize: Size of the array.
 * @pivotIdx: Pointer to store the index of the pivot
 * Return : void
 */
void partitionArray(int *array, size_t startIdx, size_t endIdx,
		size_t arraySize, size_t *pivotIdx)
{
	int pivot = array[endIdx];
	size_t idx;
	*pivotIdx = startIdx;

	for (idx = startIdx; idx < endIdx; idx++)
	{
		if (array[idx] <= pivot)
		{
			swapAndPrint(array, *pivotIdx, idx, arraySize);
			(*pivotIdx)++;
		}
	}
}

/**
 * sort_helper -  helper func for quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @startIdx: Starting index of the subarray to be sorted.
 * @endIdx: Ending index of the subarray to be sorted.
 * @arraySize: Size of the array.
 * Return: void
 */
void sort_helper(int *array, size_t startIdx, size_t endIdx, size_t arraySize)
{

	size_t pivotIdx;

	if (array == NULL || startIdx >= endIdx)
		return;

	partitionArray(array, startIdx, endIdx, arraySize, &pivotIdx);
	swapAndPrint(array, pivotIdx, endIdx, arraySize);

	if (pivotIdx > startIdx + 1)
		sort_helper(array, startIdx, pivotIdx - 1, arraySize);

	if (endIdx > pivotIdx + 1)
		sort_helper(array, pivotIdx + 1, endIdx, arraySize);
}



/**
 * quick_sort - quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		sort_helper(array, 0, size - 1, size);
	}
}
