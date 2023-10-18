#include "main.h"

/**
 * _non_interactive_mode - Function that run shell program
 * @argv: string pointer to command
 * Return: returns void
 */

void _non_interactive_mode(char **argv)
{
	char *lineptr = NULL, *ptr, *command_copy,
		 **command_argv = {NULL}, *environ[] = {NULL};

	size_t z = 0;
	ssize_t rd;
	int status = 0, c = 0, i;

	while (1)
	{
		c++;
		rd = _getline(&lineptr, &z, stdin);
		if (rd == -1)
		{
			break;
		}
		command_copy = handle_new_line(lineptr);
		ptr = get_full_path(command_copy);
		if (_strcmp(command_copy, "\n") == 0 || command_copy[0] == '#')
			continue;
		else if (_builtin_command(argv[0], command_copy, &status, c, lineptr) != -1)
		{
			free(ptr);
			continue;
		}
		else if (ptr != NULL)
		{
			command_argv = _argv(command_copy);
			i = _excut(ptr, command_argv, environ, &status);
			if (i == 0)
				_print_errors(argv[0], c, status, command_copy);
		}
		else if (ptr == NULL)
		{
			excute_notFound(command_copy, command_argv, environ, &status);
			_print_errors(argv[0], c, status, command_copy);
		}
		free(ptr);
	}
	free(lineptr);
}
