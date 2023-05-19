#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @err: output error message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell *datash, char *msg, char *err, char *ver_str)
{
	char *illegal_flag;

	_strcpy(err, datash->argv[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(err, datash->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *datash)
{
	int len, len_id;
	char *err, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	len = _strlen(datash->argv[0]) + _strlen(datash->args[0]);
	len += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = strcat_cd(datash, msg, err, ver_str);

	free(ver_str);

	return (err);
}

/**
 * error_not_found - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->argv[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->argv[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->argv[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->argv[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, datash->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);

	return (err);
}
