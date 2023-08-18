#include<stdio.h>
#include<string.h>
/**
 * _strcmp - function to concatenate two strings with the use of n
 * @s1: this takes char
 * @s2: this takes char
 * Description - strcmp
 * Return: this this the return type
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;
	
	if (!s1 || !s2)
		return (-1);

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
