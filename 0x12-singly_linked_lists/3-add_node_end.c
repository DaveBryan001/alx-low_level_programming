#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: A pointer to the head of the list.
 * @str: The string to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new__node;
	list_t *new_head;
	unsigned int i;
	unsigned int count = 0;

	new__node = malloc(sizeof(list_t));
	if (new__node == NULL)
	{
		return (NULL);
	}
	new__node->str = strdup(str);

	for (i = 0; str[i] != '\0'; i++)
	{
		count++;
	}

	new__node->len = count;
	new__node->next = NULL;
	new_head = *head;
	if (new_head != NULL)
	{
		while (new_head->next != NULL)
		{
			new_head = new_head->next;
		}
		new_head->next = new__node;
	}
	else
		*head = new__node;

	return (*head);

}
