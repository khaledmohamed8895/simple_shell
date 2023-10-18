#include "main.h"

/**
 * _builtin_command - Function excute builtin commands
 * @program_name: command name
 * @counter: number of commands
 * @status: status of process
 * @lineptr: command builtin
 * @lin: line
 * Return: return (-1) or (i)
 */

int _builtin_command(char *program_name, char *lineptr,
		int *status, int counter, char *lin)
{
	int num = 1;
	int i;
	char *cmd_copy;
	char *built_command[] = {"exit", "env", "echo"};

	cmd_copy = strdup(lineptr);
	cmd_copy = _strtok(cmd_copy, " ");
	for (i = 0; i < 2; i++)
	{
		if (_strcmp(cmd_copy, built_command[i]) == 0)
		{
			num = 0;
			free(cmd_copy);
			break;
		}
	}
	switch (i)
	{
		case 0:
			shell_exit(lineptr, status, counter, program_name, lin);
			break;
		case 1:
			_env();
			break;
	}
	if (num)
	{
		free(cmd_copy);
		return (-1);
	}
	else
		return (i);
}
