#include "sort.h"

/**
 * quick_sort - Sort a given array using the Quick
 * sort algorithm in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of @array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    sort_partition(array, size, 0, size - 1);
}

/**
 * sort_partition - Sort the partitions in the array.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The index of the first element in the
 * sublist (partition in the array).
 * @high: The index of the last element in the
 * sublist (partition in the array).
 */
void sort_partition(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, size, low, high);
        sort_partition(array, size, low, pivot - 1);
        sort_partition(array, size, pivot + 1, high);
    }
}

/**
 * partition - Perform partitioning for Quick Sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The index of the first element in the
 * sublist (partition in the array).
 * @high: The index of the last element in the
 * sublist (partition in the array).
 *
 * Return: Index of the pivot element.
 */
int partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, size);
    return i + 1;
}

/**
 * swap - Swaps two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
