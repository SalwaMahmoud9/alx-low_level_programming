#include "main.h"
/**
 * _strncat - concatenates two strings
 *
 * @dest: destination
 * @src: source
 * @n: bytes
 *
 * Return: char value
 */
char *_strncat(char *dest, char *src, int n)
{
	int x;
	int y;

	for (y = 0; dest[y] != '\0'; y++)
	{}

	for (x = 0; x < n && src[x] != '\0'; x++)
	{
		dest[y + x] = src[x];
	}
	dest[y + x] = '\0';

	return (dest);

}
