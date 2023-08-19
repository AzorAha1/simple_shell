#include "main.h"
/**
 * _strlen - function name
 * @c: argument c
 * Description - getting string length
 * Return: returns int
 */
size_t _strlen(const char *c)
{
	size_t i;
	if (!c)
	{
		return (-1);
	}
	for (i = 0; c[i] != '\0'; i++)
		;
	return (i);
}
