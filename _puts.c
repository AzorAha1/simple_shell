#include "main.h"
void _puts(char *ch)
{
	while (*ch != '\0')
	{
		print_char(*ch);
		ch++;
	}
}
