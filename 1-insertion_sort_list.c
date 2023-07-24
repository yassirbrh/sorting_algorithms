#include "sort.h"

/**
 * swap_nodes - Function
 *
 * Description: Swaps two nodes.
 *
 * @firstNode: Pointer to the first node.
 * @secondNode: Pointer to the second node.
 *
 * Return: No return because it's a void function.
 */
void swap_nodes(listint_t *firstNode, listint_t *secondNode)
{
	listint_t *tmp;

	if (firstNode->next == secondNode)
	{
		firstNode->next = secondNode->next;
		if (secondNode->next != NULL)
			secondNode->next->prev = firstNode;
		secondNode->prev = firstNode->prev;
		if (firstNode->prev != NULL)
			firstNode->prev->next = secondNode;
		firstNode->prev = secondNode;
		secondNode->next = firstNode;
	}
	else
	{
		tmp = malloc(sizeof(listint_t));
		tmp->next = firstNode->next;
		tmp->prev = firstNode->prev;
		if (secondNode->next != NULL)
			secondNode->next->prev = firstNode;
		if (secondNode->prev != NULL)
			secondNode->prev->next = firstNode;
		firstNode->next = secondNode->next;
		firstNode->prev = secondNode->prev;
		secondNode->next = tmp->next;
		secondNode->prev = tmp->prev;
		if (secondNode->prev != NULL)
			secondNode->prev->next = secondNode;
		if (secondNode->next != NULL)
			secondNode->next->prev = secondNode;
		free(tmp);
	}
}
/**
 * insertion_sort_list - Function
 *
 * Description: Sort a doubly linked list.
 *
 * @list: Pointer to the doubly linked list.
 *
 * Return: No return because it's a void function.
 */
void insertion_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *node = *list, *list_node, *iter_node;

	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		while (node != NULL)
		{
			list_node = node;
			iter_node = list_node->prev;
			node = node->next;
			sorted = 0;
			while (iter_node != NULL && sorted == 0)
			{
				sorted = 1;
				if (iter_node->n > list_node->n)
				{
					if (iter_node == *list)
						*list = list_node;
					swap_nodes(iter_node, list_node);
					print_list(*list);
					sorted = 0;
					iter_node = iter_node->prev;
				}
				iter_node = iter_node->prev;
			}
		}
	}
}
