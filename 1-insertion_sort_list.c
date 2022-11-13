#include "sort.h"
#include <stdio.h>

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *count = (*list);

    if ((*list)->next == NULL)
    {
        print_list(*list);
        return 1;
    }
    listint_t *count2 = (*list);
    listint_t *node_2_swap;

   while (count != NULL)
    {
        if (count->prev == NULL)
            count = count->next;

        if (count->n < count->prev->n)
        {
            node_2_swap = count;

            count->prev->next = count->next;
            if (!(count->next == NULL))
            {
                count->next->prev = count->prev;
            }
            node_2_swap->next = NULL;
            node_2_swap->prev = NULL;

            for (count2; count2 != NULL; count2 = count2->next)
            {
                if (count2->n > node_2_swap->n)
                {
                    if (count2->prev == NULL)
                    {
                        count2->prev = node_2_swap;
                        node_2_swap->next = count2;
                        (*list) = node_2_swap;
                        count2 = (*list);
                        print_list(*list);
                        break;
                    }
                    node_2_swap->next = count2;
                    node_2_swap->prev = count2->prev;
                    count2->prev->next = node_2_swap;
                    count2->prev = node_2_swap;
                    count2 = (*list);
                    print_list(*list);
                    break;
                }
            }
        }
        count = count->next;
    }
}
