#include "main.h"
/**
 * get_input - function get input with getline
 * Return: input
 */
char *get_input()
{
	char *input = NULL;
	size_t size = 0;
	ssize_t ret_num;

	if (isatty(STDIN_FILENO))
		printf("$ ");
	fflush(stdout);
	ret_num = getline(&input, &size, stdin);
	if (ret_num == -1)
	{
		free(input);
		input = NULL;
		if (isatty(STDIN_FILENO))
			printf("\n");
		perror("$");
		exit(EXIT_FAILURE);
	}
	input[ret_num - 1] = '\0';
	return (input);
}
