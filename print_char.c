#include "main.h"
/**
 * print_char - function name
 * @ch: argument that takes character
 * Description - function to print a character
 * Return: returns void
*/
void print_char(char ch)
{
	write(1, &ch, 1);
}
