#include "main.h"
/**
 * _strdup - function name
 * @str: argument to be duplicated
 * Description - function to duplicate
 * Return: returns char pointer
*/
char *_strdup(char *str)
{
    char *dupl, *dupl2;
    int str_size;

    str_size = _strlen(str);
    dupl = (char *)malloc(sizeof(char) * (str_size + 1));
    if (!dupl)
    {
        return (NULL);
    }
    dupl2 = dupl;
    while (*str)
    {
        *dupl2 = *str;
        dupl2++;
        str++;
    }
    *dupl2 = '\0';
    return (dupl);
}