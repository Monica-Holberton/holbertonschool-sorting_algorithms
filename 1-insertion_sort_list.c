#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
* using the Insertion sort algorithm
* @list: Double pointer to the head of the doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *insert, *tmp;

/* Check if the list is valid and contains at least 2 elements */
if (!list || !*list || !(*list)->next)
return;

/* Start from the second node */
current = (*list)->next;
while (current)
{
tmp = current->next; /* Save the next node to continue later */
insert = current->prev;

/* Move current node leftward as long as it's smaller than previous nodes */
while (insert && current->n < insert->n)
{
/* Re-link insert's previous node to current */
if (insert->prev)
insert->prev->next = current;
current->prev = insert->prev;

/* Re-link current's next node to insert */
insert->next = current->next;
if (current->next)
current->next->prev = insert;

/* Link current and insert */
current->next = insert;
insert->prev = current;

/* Update head of the list */
if (!current->prev)
*list = current;

/* Update insert pointer for next comparison */
insert = current->prev;

/* Print the list after every swap */
print_list(*list);
}

/* Move to the next node in the list */
current = tmp;
}
}
