#include "main.h"
/**
* free_data - frees data structure
*
* @datash: data structure
* Return: Nothing
*/
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_env[i]; i++)
	{
		free(datash->_env[i]);
	}
	free(datash->_env);
	free(datash->pid);
}

/**
* set_data - Initialize data structure
*
* @datash: data structure
* @argv: argument vector
* Return: no return
*/
void set_data(data_shell *datash, char **argv)
{
	unsigned int i;

	datash->argv = argv;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;
	datash->_env = malloc(sizeof(char *) * (i + 1));
	for (i = 0; environ[i]; i++)
	{
		datash->_env[i] = _strdup(environ[i]);
	}
	datash->_env[i] = NULL;
	datash->pid = aux_itoa(getpid());
}
/**
* main - Entry point
*
* @argc: argument count
* @argv: argument vector
*
* Return: 0 on success.
*/
int main(int argc, char **argv)
{
	data_shell datash;
	(void) argc;

	signal(SIGINT, get_sigint);
	set_data(&datash, argv);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
