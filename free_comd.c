#include "main.h"
/**
 * free_commands - free the command memory
 * @command: command to free its memory
 * Return: NULL
 */
void free_commands(char **command)
{
	int i;

	for (i = 0; command[i] != NULL; i++)
	{
		free(command[i]);
	}
	free(command);
}
