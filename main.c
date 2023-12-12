#include "main.h"
/**
 * main - main function
 * Return: 0
 */
int main(void)
{
	char *input = NULL, **tok_ret = NULL;
	size_t size = 0, command_count = 0;
	ssize_t ret_num;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);
		ret_num = getline(&input, &size, stdin);
		++command_count;
		if (ret_num == -1)
		{
			free(input);
			input = NULL;
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(EXIT_FAILURE);
		}
		input[ret_num - 1] = '\0';
		if (*input == '\0')
			continue;
		tok_ret = tokenize(input, " ");
		if (tok_ret == NULL)
			continue;
		if (access(tok_ret[0], X_OK) == -1)
		{
			get_pathname(&tok_ret[0]);
			if (tok_ret != NULL && access(tok_ret[0], X_OK) == -1)
			{
				exit_func(tok_ret, command_count);
				env_func(tok_ret, command_count);
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
