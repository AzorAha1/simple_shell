#include "main.h"
void error_message(char *argv, int counter, char *arr)
{
	int *anothercounter;
	char *not_found = "not found\n";

	anothercounter = &counter;
	write(1, argv, _strlen(argv));
	putchar(':');
	putchar(' ');
	fflush(stdout);
	write(1, anothercounter, sizeof(int));
	putchar(':');
	putchar(' ');
	fflush(stdout);
	write(1, arr, _strlen(arr));
	putchar(':');
	putchar(' ');
	fflush(stdout);
	write(1, not_found, _strlen(not_found));
}
