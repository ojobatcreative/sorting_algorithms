#include "sort.h"

/**
 * node_swap - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @t1: A pointer to the first node to swap.
 * @t2: The second node to swap.
 */
void node_swap(listint_t **h, listint_t **t1, listint_t *t2)
{
	(*t1)->next = t2->next;
	if (t2->next != NULL)
		t2->next->prev = *t1;
	t2->prev = (*t1)->prev;
	t2->next = *t1;
	if ((*t1)->prev != NULL)
		(*t1)->prev->next = t2;
	else
		*h = t2;
	(*t1)->prev = t2;
	*t1 = t2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			node_swap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
