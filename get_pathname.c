#include "main.h"
/**
 * get_pathname - function add path to command
 * @command: command to add path to
 * Return: void
 */
void get_pathname(char **command)
{
	char *tok, *path_dirs, *new_pathname, *dup_path_dirs;

	if (*command == NULL || command == NULL)
		return;
	path_dirs = getenv("PATH");
	dup_path_dirs = strdup(path_dirs);
	tok = strtok(dup_path_dirs, ":");
	while (tok != NULL)
	{
		new_pathname = malloc(sizeof(char) * (strlen(*command) + strlen(tok) + 2));
		if (new_pathname == NULL)
		{
			/*fprintf(stderr, "memory allocation failure");*/
			return;
		}
		strcpy(new_pathname, tok);
		strcat(new_pathname, "/");
		strcat(new_pathname, *command);
		strcat(new_pathname, "\0");
		if (access(new_pathname, X_OK) == 0)
		{
			free(*command);
			*command = strdup(new_pathname);
			free(new_pathname);
			break;
		}
		free(new_pathname);
		tok = strtok(NULL, ":");
	}
	free(dup_path_dirs);
}
