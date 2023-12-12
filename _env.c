#include "main.h"
/**
 * env_func - print enivonment variable
 * @tok_ret: command to determine exit
 * @command_count: count error command
 * Return: VOID
 */
void env_func(char **tok_ret, size_t command_count)
{
	size_t i;
		if (strcmp(tok_ret[0], "env") == 0)
		{
			while (environ[i] != NULL)
			{
				printf("%s\n", environ[i]);
				i++;
			}
		}
		else
		{
			fprintf(stderr, "%s: %lu: not found\n", tok_ret[0],
			command_count);
			free_commands(tok_ret);
		}
}
