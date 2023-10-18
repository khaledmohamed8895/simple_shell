#include "main.h"
/**
 * shell_exit - Function that used to exit from the shell
 * @lineptr: the command line
 * @status: Status of the process
 * @counter: Count the number of commands
 * @program_name: name of the programe
 * @lin: the command
 * Return: returns exit status
 */

int shell_exit(char *lineptr, int *status, int counter,
			   char *program_name, char *lin)
{
	int ex_status = 0, ln, valid_num = 1, i;
	char *str;
	char *command_copy;

	command_copy = strdup(lineptr);
	command_copy = _strtok(command_copy, " ");
	str = _strtok(NULL, " ");
	if (!str)
	{
		free(lin);
		free(command_copy);
		exit(*status);
	}
	ln = _strlen(str);
	if (str != NULL)
	{
		if (str[0] == '-')
			valid_num = 0;
		for (i = 0; i < ln; i++)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
			{
				valid_num = 0;
				break;
			}
		}
		if (valid_num)
		{
			ex_status = atoi(str);
			free(lineptr);
			free(command_copy);
			exit(ex_status);
		}
		else
		{
			*status = 2;
			_print_errors(program_name, counter, *status, lineptr);
			free(command_copy);
		}
	}
	return (ex_status);
}
