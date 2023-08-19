#include "main.h"
/**
 * _strlen - function name
 * @c: argument c
 * Description - getting string length
 * Return: returns int
 */
int _strlen(char *c)
{
	int length;

	while(c[length] != '\0')
	{
		length++;
	}
	return (length);
}
