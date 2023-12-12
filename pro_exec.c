#include "main.h"
/**
 * pro_exec - function process and execute the command supply
 * @commands: command to execute
 * Return: NULL
 */
void pro_exec(char **commands)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
		return;

	if (child_pid == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
			perror("execve");
	}
	else
		waitpid(child_pid, &status, 0);
}
