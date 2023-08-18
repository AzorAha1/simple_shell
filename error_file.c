#include "main.h"
void error_message(char *argv, int counter, char *arr)
{
	int *anothercounter;
	char *not_found = "not found\n";

	anothercounter = &counter;
	write(1, argv, strlen(argv));
	putchar(':');
	putchar(' ');
	fflush(stdout);
	write(1, anothercounter, 1);
	putchar(':');
	putchar(' ');
	fflush(stdout);
	write(1, arr, strlen(arr));
	putchar(':');
	putchar(' ');
	fflush(stdout);
	write(1, not_found, strlen(not_found));
}
