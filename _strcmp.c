#include<stdio.h>
#include<string.h>
/**
 * _strcmp - function to concatenate two strings with the use of n
 * @s1: this takes char
 * @s2: this takes char
 * Description - strcmp
 * Return: this this the return type
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[1] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (s1[i] - s2[i]);
}
