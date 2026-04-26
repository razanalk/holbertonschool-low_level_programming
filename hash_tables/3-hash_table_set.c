#include "hash_tables.h"
#include <string.h>

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
	hash_node_t *node, *tmp;
	unsigned long int index;
	char *val_dup, *key_dup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];

	/* check if key exists */
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			val_dup = strdup(value);
			if (val_dup == NULL)
				return (0);

			free(tmp->value);
			tmp->value = val_dup;
			return (1);
		}
		tmp = tmp->next;
	}

	/* create new node */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	key_dup = strdup(key);
	val_dup = strdup(value);

	if (key_dup == NULL || val_dup == NULL)
	{
		free(node);
		free(key_dup);
		free(val_dup);
		return (0);
	}

	node->key = key_dup;
	node->value = val_dup;

	/* insert at beginning */
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
