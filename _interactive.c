#include "main.h"
/**
 * _interactive_mode - Function used to run shell in interactive mode
 * @argv: array pointer to commands
 * Return: function return void.
 */
void _interactive_mode(char **argv)
{
	char *lineptr = NULL, *ptr, *command_copy,
	      **command_argv = {NULL}, *environ[] = {NULL};
	ssize_t rd;
	int status = 0, z = 0, i;
	size_t s = 0;

	while (1)
	{
		z++;
		write(1, "$ ", sizeof("$ ") - 1);
		rd = _getline(&lineptr, &s, stdin);
		if (rd == -1)
		{
			write(1, "\n", 1);
			break;
		}
		command_copy = handle_new_line(lineptr);
		ptr = get_full_path(command_copy);
		if (_strcmp(command_copy, "\n") == 0 || command_copy[0] == '#')
			continue;
		else if (_builtin_command(argv[0], command_copy, &status, z, lineptr) != -1)
		{
			free(ptr);
			continue;
		}
		else if (ptr != NULL)
		{
			command_argv = _argv(command_copy);
			i = _excut(ptr, command_argv, environ, &status);

			if (i == 0)
				_print_errors(argv[0], z, status, command_copy);
		}
		else if (ptr == NULL)
		{
			excute_notFound(command_copy, command_argv, environ, &status);
			_print_errors(argv[0], z, status, command_copy);
		}
		free(ptr);
	}
	free(lineptr);
}
