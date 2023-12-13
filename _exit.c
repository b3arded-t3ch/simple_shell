#include "main.h"
/**
 * exit_func - exit the programme
 * @tok_ret: command to determine exit
 * Return: VOID
 */
void exit_func(char **tok_ret)
{
	if (strcmp(tok_ret[0], "exit") == 0)
	{
		free_commands(tok_ret);
		exit(0);
	}
}
