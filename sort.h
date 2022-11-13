#ifndef SORT_H
#define SORT_H


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

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

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void print_array(const int *array, size_t size);

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list);


/**
 * bubble_sort - Entry point
 *
 * Return: None
 */
void bubble_sort(int *array, size_t size);


/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @list: main list
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
void insertion_sort_list(listint_t **list);

#endif
