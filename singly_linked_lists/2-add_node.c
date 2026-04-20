#include <stdlib.h>
#include "lists.h"

/**
 * _strlen - calculates length of a string
 * @s: input string
 * Return: length
 */
unsigned int _strlen(const char *s)
{
	unsigned int len = 0;

	while (s && s[len] != '\0')
		len++;

	return (len);
}

/**
 * add_node - adds a new node at the beginning of a list
 * @head: pointer to head
 * @str: string to add
 * Return: address of new element, or NULL if failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	new->len = _strlen(str);
	new->next = *head;
	*head = new;

	return (new);
}
