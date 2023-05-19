#include "main.h"

/**
* without_comment - deletes comments from the input
*
* @input: input string
* Return: input without comments
*/
char *without_comment(char *input)
{
	int i, up_to;
	
	up_to = 0;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '#')
		{
			if (i == 0)
			{
				free(input);
				return (NULL);
			}
			if (input[i - 1] == ' ' || input[i - 1] == '\t' ||
				input[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		input = _realloc(input, i, up_to + 1);
		input[up_to] = '\0';
	}

	return (input);
}

/**
* shell_loop - Loop of shell
* @datash: data relevant (av, input, args)
*
* Return: no return.
*/
void shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *in;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		in = read_line(&i_eof);
		if (i_eof != -1)
		{
			in = without_comment(in);
			if (in == NULL)
				continue;
			if (check_syntax_error(datash, in) == 1)
			{
				datash->status = 2;
				free(in);
				continue;
			}
			in = rep_var(in, datash);
			loop = split_commands(datash, in);
			datash->counter += 1;
			free(in);
		}
		else
		{
			loop = 0;
			free(in);
		}
	}
}
