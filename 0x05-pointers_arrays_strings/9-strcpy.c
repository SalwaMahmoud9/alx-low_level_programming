#include "main.h"
#include "2-strlen.c"
/**
 * _strcpy - copies the string pointed to by src
 *
 * @dest: destination
 * @src: src
 *
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
