#include "main.h"
/**
 * exit_func - exit the programme
 * @tok_ret: command to determine exit
 * Return: VOID
 */
void exit_func(char **tok_ret)
{
	int status = 0;
	if (strcmp(tok_ret[0], "exit") == 0)
	{
		if (tok_ret[1] != NULL)
		{
			status = atoi(tok_ret[1]);
			free_commands(tok_ret);
			exit(status);
		}
		free_commands(tok_ret);
		exit(status);
	}
}
