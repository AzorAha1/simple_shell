#include "main.h"
void handle_comment(char *input)
{
	int i;

	for (i = 0; input[i]; i++)
	{
		if (i > 0 && input[i] == '#' && input[i - 1] != ' ')
		{
			break;
		}
		if (input[i] == '#')
		{
			input[i] = '\0';
		}
	}
}
