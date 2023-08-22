#include "main.h"
/**
 * _strcat - custom function to concatenate strings
 * @s1: this is the destination
 * @s2: this is the source
 * Description - this function concatenates s2 to s1
 * Return: returns s1
*/
char *_strcat(char *s1, char *s2)
{
    int i;
    int j;
    if (!s1 || !s2)
    {
        return (NULL);
    }
    for (i = 0; s1[i] != '\0'; i++)
        ;
    j = 0;

    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        j++;
        i++;
    }
    s1[i] = '\0';
    return (s1);
}