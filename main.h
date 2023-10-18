fndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DELIMITERS " \t\r\n\a\""

/*Env command*/
char *_getenv(char *nameptr);
void _env(void);
extern char **environ;

/*Exit command*/
int shell_exit(char *lineptr, int *status, int counter, char *program_name, char *lin);

/*Excution commands*/
char *handle_new_line(char *line);
int _builtin_command(char *program_name, char *lineptr, int *status, int counter, char *lin);
char *get_full_path(char *lineptr);
char **_argv(char *lineptr);
int _excut(char *user_cmd, char **argv, char *env[], int *status);
void excute_notFound(char *lineptr, char **command_argv, char *envi[], int *status);

/*Custom string functions*/
char *_strdup(char *string);
void _strcat(char *string1, const char *string2);
int _strlen(char *p);
char *_strcpy(char *dest, char *src);
int _strcmp(char *string1, char *string2);
int _atoi(char *string);
char *print_num(int num);

/*non,interactive modes*/
void _interactive_mode(char **argv);
void _non_interactive_mode(char **argv);

/*Errors*/
void _print_errors(char *program_name, int counter, int status, char *lineptr);
void _command_error(char *program_name, char *counter, char *lineptr);
void _path_errors(char *program_name, char *counter, char *lineptr);
void shell_exit_error(char *program_name, char *counter, char *lineptr);

/*Advanced functions*/
char *_strtok(char *string, const char *delimiters);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif
