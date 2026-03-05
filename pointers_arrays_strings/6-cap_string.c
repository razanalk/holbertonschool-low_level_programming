#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string
 * Return: str
 */

char *cap_string(char *str)
{
int i = 0;
char sep[] = " \t\n,;.!?\"(){}";
int j;

if (str[0] >= 'a' && str[0] <= 'z')
str[0] -= 32;

while (str[i] != '\0')
{
j = 0;
while (sep[j] != '\0')
{
if (str[i] == sep[j])
{
if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
str[i + 1] -= 32;
}
j++;
}
i++;
}

return (str);
}
