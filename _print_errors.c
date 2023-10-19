#include "main.h"
/**
 * _print_errors - Function that print error
 *
 * @program_name: name of program
 * @counter: number of commands
 * @status: Status of process
 * @lineptr: command from user
 *
 * Return: void.
 */
void _print_errors(char *program_name, int counter, int status, char *lineptr)
{
	char *num;

	num = print_num(counter);
	if (status == 126)
		_path_errors(program_name, num, lineptr);
	if (status == 127)
		_command_error(program_name, num, lineptr);
	if (status == 2 && (strncmp(lineptr, "exit", 4) == 0))
		shell_exit_error(program_name, num, lineptr);
	free(num);
}

/**
 * _path_errors - Function prints path error
 *
 * @program_name: name of program
 * @counter: number of commands
 * @lineptr: command from user
 *
 * Return: void
 */
void _path_errors(char *program_name, char *counter, char *lineptr)
{
	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	write(2, counter, strlen(counter));
	write(2, ": ", 2);
	write(2, lineptr, (int)strlen(lineptr));
	write(2, ": ", 2);
	write(2, "Permission denied", sizeof("Permission denied") - 1);
	write(2, "\n", 1);
}

/**
 * _command_error - Function prints errors
 *
 * @program_name: name of program
 * @counter: number of commands
 * @lineptr: command from user
 * Return: void
 */
void _command_error(char *program_name, char *counter, char *lineptr)
{
	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	write(2, counter, strlen(counter));
	write(2, ": ", 2);
	write(2, lineptr, (int)strlen(lineptr));
	write(2, ": ", 2);
	write(2, "not found", sizeof("not found") - 1);
	write(2, "\n", 1);
}

/**
 * shell_exit_error - Function prints errors
 *
 * @program_name: name of program
 * @counter: number of commands
 * @lineptr: command from user
 * Return: void
 */
void shell_exit_error(char *program_name, char *counter, char *lineptr)
{

	char *token;

	strtok(lineptr, DELIMITERS);
	write(2, program_name, _strlen(program_name));
	write(2, ": ", 2);
	write(2, counter, strlen(counter));
	write(2, ": ", 2);
	write(2, lineptr, (int)strlen(lineptr));
	write(2, ": ", 2);
	write(2, "Illegal number", sizeof("Illegal number:") - 1);
	write(2, ": ", 2);
	token = strtok(NULL, DELIMITERS);
	write(2, token, (int)strlen(token));
	write(2, "\n", 1);
}

/**
 * print_num - function return number of string
 * @num: parameter an integer
 * Return: pointer to number chararcter of string
 */

char *print_num(int num)
{
	unsigned int id;
	unsigned int x;

	int len = 0;
	int j = 0;

	char *counter;

	id = num;
	x = 1;

	while (id > 9)
	{
		id /= 10;
		x *= 10;
		len++;
	}
	len++;
	counter = (char *)malloc(len + 1);
	if (counter == NULL)
		return (NULL);
	for (; x >= 1; x /= 10)
	{
		counter[j++] = ((num / x) % 10) + '0';
	}
	counter[len] = '\0';
	return (counter);
}

