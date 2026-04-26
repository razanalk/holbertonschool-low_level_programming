#include "hash_tables.h"
#include <string.h>

/**
 * update_value - updates existing key
 * @node: node
 * @value: new value
 *
 * Return: 1 if success, 0 if fail
 */
int update_value(hash_node_t *node, const char *value)
{
	char *val_dup;

	val_dup = strdup(value);
	if (val_dup == NULL)
		return (0);

	free(node->value);
	node->value = val_dup;

	return (1);
}

/**
 * create_node - creates new node
 * @key: key
 * @value: value
 *
 * Return: pointer or NULL
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);

	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - adds element to hash table
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *tmp, *new_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (update_value(tmp, value));
		tmp = tmp->next;
	}

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
