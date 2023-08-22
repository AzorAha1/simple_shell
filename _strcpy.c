#include "main.h"
/**
 * _strcpy - custom function to string copy
 * @s1: s1 will act as the destinaton
 * @s2: s2 will be the source
 * Description - this function copies from s2 to s1
 * Return: return a char type
*/
char *_strcpy(char *s1, char *s2)
{
    int i;
    
    if (!s1 || !s2)
    {
        return (NULL);
    }
    for (i = 0; s2[i] != '\0'; i++)
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return (s1);
}
