#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
int i = 0;

while (s && s[i])
i++;

return (i);
}

/**
 * _strcpy - copies string
 * @dest: destination
 * @src: source
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src && src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';

return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name
 * @age: age
 * @owner: owner
 * Return: pointer to new dog, or NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
int name_len, owner_len;

if (name == NULL || owner == NULL)
return (NULL);

dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);

name_len = _strlen(name);
owner_len = _strlen(owner);

dog->name = malloc(name_len + 1);
if (dog->name == NULL)
{
free(dog);
return (NULL);
}

dog->owner = malloc(owner_len + 1);
if (dog->owner == NULL)
{
free(dog->name);
free(dog);
return (NULL);
}

_strcpy(dog->name, name);
_strcpy(dog->owner, owner);
dog->age = age;

return (dog);
}
