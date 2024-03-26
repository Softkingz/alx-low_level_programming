#include "main.h"

/**
 * _memcpy - copies n bytes of memory from a source and places them
 * in a destination. The memory areas must not overlap
 *
 * @dest: where the copied bytes are to be placed
 *
 * @src: Where bytes are copied from
 *
 * @n: size of bytes to be copied in the buffer
 *
 * Return: Nothing
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
