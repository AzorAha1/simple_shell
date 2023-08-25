#include "main.h"
/**
 * print_char - function name
 * @ch: argument that takes character
 * Description - function to print a character
 * Return: returns void
*/
int print_char(char ch)
{
	return write(2, &ch, 1);
}
