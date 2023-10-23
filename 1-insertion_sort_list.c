#include "sort.h"
/**
 * insertion_sort_list - Function sorts list
 * @list: link to unsorted list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *new;

	if (list == NULL || (*list)->next == NULL)
		return;
	new = (*list)->next;
	while (node)
	{
		while ((new->prev) && (new->prev->n > new->n))
		{
			new = swap_node(new, list);
			print_list(*list);
		}
		new = new->next;
	}
}

/**
 *swap_node - function swap a node helper
 *@node: first node
 *@list: a node list
 *Return: pointer to the current node
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
