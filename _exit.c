#include "main.h"
/**
 * exit_func - exit the programme
 * @tok_ret: command to determine exit
 * @command_count: count error command
 * Return: VOID
 */
void exit_func(char **tok_ret, size_t command_count)
{
	int status = atoi(tok_ret[1]);
	if (strcmp(tok_ret[0], "exit") == 0)
	{
		free_commands(tok_ret);
		exit(status);
	}
	fprintf(stderr, "%s: %lu: not found\n", tok_ret[0],
	command_count);
	free_commands(tok_ret);
}
