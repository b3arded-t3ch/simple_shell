#include "main.h"
/**
 * tokenize - return array of a string
 * @str: string to be tokenize
 * @delim: delimiter use for tokenization
 * Return: success arr_str, otherwise NULL
 */
char **tokenize(char *str, const char *delim)
{
	char *token, **arr_str, *str_cpy;
	size_t n_tok;

	if (str == NULL || *str == '\0')
		return (NULL);

	str_cpy = strdup(str);

	token = strtok(str, delim);
	n_tok = 0;
	while (token != NULL)
	{
		++n_tok;
		token = strtok(NULL, delim);
	}
	if (n_tok > 0)
	{	arr_str = malloc(sizeof(char *) * (n_tok + 1));
		if (arr_str == NULL)
		{
		/*	fprintf(stderr, "memory allocation failure");*/
			exit(EXIT_FAILURE);
		}
		token = strtok(str_cpy, delim);
		n_tok = 0;
		while (token != NULL)
		{
			arr_str[n_tok] = strdup(token);
			token = strtok(NULL, delim);
			n_tok++;
		}
		arr_str[n_tok] = NULL;
	}
	free(str_cpy);
	return (arr_str);
}
