/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** fill_command_arguments
*/

/// \file server/src/core/fill_command_arguments.c

#include "cli_commands.h"
#include "rcodes.h"
#include <stdlib.h>
#include <string.h>

/// \brief Skip the beginning of the command until a ' ' is found.
/// \param char *The command to be skip.
/// \return The command without the command name.
static char *skip_command(char *command)
{
    int i = 0;

    while (command && command[i] && command[i] != ' ')
        i++;
    if (!command || !command[i])
        return (NULL);
    command = command + i;
    return (command);
}

/// \brief Fill the command arguments in the structure, according to the
/// corresponding command.
/// \param char *The command which point at the beginning of the argument.
/// \param int The number of argument the command need.
/// \param char **The array to be fill, it will be return at the end.
/// \return The array of argument, or NULL if an error occurs.
static char **fill_arguments(char *command, int arg_number, char **args)
{
    int arg_len = 0;

    for (int i = 0; i < arg_number; i++) {
        if (command[0] != ' ' || command[1] != '"' || command[2] == '\n') {
            args[i] = NULL;
            return args;
        }
        command = command + 2;
        for (arg_len = 0; command[arg_len] && command[arg_len] != '"';
        arg_len++);
        if (!command[arg_len])
            return (NULL);
        args[i] = malloc(sizeof(char) * (arg_len + 1));
        strncpy(args[i], command, arg_len);
        args[i][arg_len] = '\0';
        command = command + arg_len + 1;
    }
    args[arg_number] = NULL;
    return ((command[0]) ? NULL : args);
}

/// \brief Skip the command name and get all arguments from the command.
/// \param char *The command to be parse.
/// \param int The number of arguments the command need.
/// \return The array of argument.
static char **get_arguments(char *command, int arg_number)
{
    char **args = NULL;

    command = skip_command(command);
    if (!command)
        return (NULL);
    args = malloc(sizeof(char *) * (arg_number + 1));
    if (!args)
        return (NULL);
    args = fill_arguments(command, arg_number, args);
    return (args);
}

char **fill_command_arguments(char *command, char *name, user_list_t *users)
{
    char **args = NULL;
    const cli_command_t *cmd = get_cli_command_by_name(name);
    int i = 0;

    if (!cmd) {
        print_retcode(530, NULL, users->user_peer);
        return (NULL);
    }
    for (i = 0; cmd->arguments && cmd->arguments[i]; i++);
    if (i)
        args = get_arguments(command, i);
    return (args);
}