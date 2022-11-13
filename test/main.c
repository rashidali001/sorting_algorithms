#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/** FUNCTION DEFINITION **/

listint_t *create_listint(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);


/** PRINTING A LIST **/

void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}

/**CREATING A LIST **/

listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/** INSERTION FUNCTION **/

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

/** MAIN FUNCTION **/

int main()
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
