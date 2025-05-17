#include "sort.h"
#include <stdio.h>

/**
* print_list - Prints a doubly linked list
* @list: Pointer to the head of the list
*/
void print_list(const listint_t *list)
{
int first = 1;

while (list)
{
if (!first)
printf(", ");
printf("%d", list->n);
first = 0;
list = list->next;
}
printf("\n");
}

/**
* insertion_sort_list - Sorts a doubly linked list using Insertion Sort
* @list: Double pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;

if (!list || !*list || !(*list)->next)
return;

current = (*list)->next;

while (current)
{
tmp = current;
current = current->next;

while (tmp->prev && tmp->n < tmp->prev->n)
{
listint_t *prev = tmp->prev;

/* Swap tmp and prev */
prev->next = tmp->next;
if (tmp->next)
tmp->next->prev = prev;

tmp->prev = prev->prev;
tmp->next = prev;

if (prev->prev)
prev->prev->next = tmp;
else
*list = tmp;

prev->prev = tmp;

print_list(*list);
}
}
}
