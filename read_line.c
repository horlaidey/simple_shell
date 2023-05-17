#include "main.h"

/**
 * read_line - reads the input string.
 *
 * @line_val: return value of getline function
 * Return: input string
 */
char *read_line(int *line_val)
{
	char *input = NULL;
	size_t bufsize = 0;

	*line_val = getline(&input, &bufsize, stdin);

	return (input);
}
