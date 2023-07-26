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
	firstNode->next = secondNode->next;
	if (secondNode->next != NULL)
		secondNode->next->prev = firstNode;
	secondNode->prev = firstNode->prev;
	if (firstNode->prev != NULL)
		firstNode->prev->next = secondNode;
	firstNode->prev = secondNode;
	secondNode->next = firstNode;
}
/**
 * cocktail_sort_list - Function
 *
 * Description: Sorts a doubly linked list of integers in ascending order
 *              using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list.
 *
 * Return: No return because it's a void function.
 */
void cocktail_sort_list(listint_t **list)
{
	int sorted = 0;
	listint_t *node, *rev_node;

	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		while (sorted == 0)
		{
			sorted = 1;
			node = (*list)->next;
			while (node != NULL)
			{
				if (node->prev->n > node->n)
				{
					sorted = 0;
					if (node->prev == *list)
						*list = node;
					swap_nodes(node->prev, node);
					print_list(*list);
				}
				if (node->next == NULL)
					rev_node = node->prev;
				node = node->next;
			}
			if (sorted == 1)
				break;
			sorted = 1;
			while (rev_node != NULL)
			{
				if (rev_node->n > rev_node->next->n)
				{
					sorted = 0;
					if (rev_node == *list)
						*list = rev_node->next;
					swap_nodes(rev_node, rev_node->next);
					print_list(*list);
				}
				rev_node = rev_node->prev;
			}
		}
	}
}
