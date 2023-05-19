#include "main.h"

/**
* cd_shell - changes current directory
*
* @datash: data relevant
* Return: 1 on success
*/
int cd_shell(data_shell *datash)
{
	char *dir;
	int ishome, is_home, is_dash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		is_home = _strcmp("~", dir);
		is_dash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !is_home || !is_dash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
