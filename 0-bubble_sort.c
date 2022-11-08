#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts the elements in a list
 *
 * @array: list to be received
 * @size: number of elements in the list
 */
void bubble_sort(int *array, size_t size)
{
`   unsigned int temp, loop_operation, loop_array;


    for (loop_operation = 1; loop_operation <= size; loop_operation++)
    {
        bool swapped = false;
        for (loop_array = 0; loop_array < (size - loop_operation); loop_array++)
        {
            if (array[loop_array] > array[loop_array + 1])
            {
                temp = array[loop_array];
                array[loop_array] = array[loop_array + 1];
                array[loop_array + 1] = temp;
                swapped = true;
                print_array(array, size);
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
