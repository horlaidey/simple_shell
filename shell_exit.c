#include "main.h"

/**
* exit_shell - exits the shell
*
* @datash: data relevant (status and args)
* Return: 0 on success.
*/
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;
	int is_digit;
	int len;
	int number;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		len = _strlen(datash->args[1]);
		number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || len > 10 || number)
		{
			get_err(datash, 2);
			datash->status = 2;
			return (1);
		}

		datash->status = (ustatus % 256);
	}
	return (0);
}
