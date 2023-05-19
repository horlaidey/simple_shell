#include "main.h"

/**
 * aux_help - Help information for the builtin help.
 * Return: no return
 */
void aux_help(void)
{
	char *helps = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, helps, _strlen(helps));
	helps = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, helps, _strlen(helps));
	helps = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, helps, _strlen(helps));
}
/**
 * aux_help_alias - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_alias(void)
{
	char *helps = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, helps, _strlen(helps));
	helps = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, helps, _strlen(helps));
}
/**
 * aux_help_cd - Help information for the builtin alias.
 * Return: no return
 */
void aux_help_cd(void)
{
	char *helps = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, helps, _strlen(helps));
	helps = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, helps, _strlen(helps));
}
