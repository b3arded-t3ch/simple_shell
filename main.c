#include "main.h"
/**
 * main - main function
 * Return: 0
 */
int main(int ac, char **av)
{
	char *input = NULL, **tok_ret = NULL;

	(void) ac;
	while (1)
	{
		input = get_input();
		if (*input == '\0')
			continue;
		tok_ret = tokenize(input, " ");
		if (tok_ret == NULL)
			continue;
		if (access(tok_ret[0], X_OK) == -1)
		{
			exit_func(tok_ret);
			get_pathname(&tok_ret[0]);
			if (tok_ret != NULL && access(tok_ret[0], X_OK) == -1)
			{
				perror(av[0]);
				free_commands(tok_ret);
				continue;
			}
		}
		pro_exec(tok_ret);
		free(input);
		free_commands(tok_ret);
		tok_ret = NULL;
		input = NULL;
	}
	return (0);
}
