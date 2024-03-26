#include "main.h"
#include <string.h>

/**
 * _strchr - Returns a pointer to the first occurence of the character
 * c in the string s or null if character isn't found
 *
 * @s: string containing the character to be checked
 *
 * @c: Character to be checked
 *
 * Return: Pointer to first occurrence of of c character
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			s++;
		else
			return (s);
	}

	if (c == '\0')
		return (s);

	return (NULL);
}
