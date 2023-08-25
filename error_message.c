#include "main.h"
void errorm(char *argv, int counter, char *ac)
{
	_puts(argv);
	_puts(": ");
	print_char(counter);
	_puts(ac);
	_puts(": not found\n");
}
