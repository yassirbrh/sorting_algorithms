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
	listint_t *node, *list_node, *other_node;

	while (*list != NULL && sorted == 0)
	{
		sorted = 1;
		node = *list;
		while (node->next != NULL)
		{
			list_node = node;
			node = node->next;
			other_node = node;
			while ((list_node->n > other_node->n) && other_node != NULL)
			{
				swap_nodes(list_node, other_node);
				if (list_node == *list)
					*list = other_node;
				print_list(*list);
				other_node = other_node->next;
				sorted = 0;
			}
		}
	}
}
