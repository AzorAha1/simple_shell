#include <stdio.h>
void error_message(char *ar, int line_counter, char *current_argument, char *found_error)
{
	printf("%s: %d %s %s\n", ar, line_counter, current_argument, found_error);
}
