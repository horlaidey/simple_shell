#include "main.h"

/**
* cmp_env_name - compares environment variables names
* with the input names.
* @nenv: name of the environment variable
* @name: the passed name
*
* Return: 0 if they are not equal. Another value if otherwise.
*/
int cmp_env_name(const char *nenv, const char *name)
{
	int index;

	for (index = 0; nenv[index] != '='; index++)
	{
		if (nenv[index] != name[index])
		{
			return (0);
		}
	}

	return (index + 1);
}

/**
* _getenv - get an environment variable
* @name: name of the environment variable
* @_environ: environment variable
*
* Return: value of the environment variable if is found.
* otherwise returns NULL.
*/
char *_getenv(const char *name, char **_environ)
{
	char *env_ptr;
	int index, mov;

	/* Initialize ptr_env value */
	env_ptr = NULL;
	mov = 0;

	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (index = 0; _environ[index]; index++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[index], name);
		if (mov)
		{
			env_ptr = _environ[index];
			break;
		}
	}

	return (env_ptr + mov);
}

/**
* _env - prints the evironment variables
*
* @datash: data relevant.
* Return: 1 on success.
*/
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
