#include "main.h"

/**
 * _argv - Function That generate all the arguments
 * @lineptr: pointer to string from getline
 * Return: pointer array of strings
 */

char **_argv(char *lineptr)
{
	char **argv, *_token;
	int x = 0;

	argv = malloc(sizeof(char *) * (_strlen(lineptr) + 1));

	if (!argv)
		perror("malloc");

	_token = _strtok(lineptr, DELIMITERS);
	while (_token)
	{
		if (_token[0] == '#')
			break;
		argv[x] = _token;
		_token = _strtok(NULL, DELIMITERS);
		x++;
	}

	argv[x] = NULL;
	return (argv);
}
