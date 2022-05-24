/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** fill_command_arguments
*/

#include "cli_commands.h"
#include <stdlib.h>
#include <string.h>

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

static char **fill_arguments(char *command, int arg_number, char **args)
{
    int arg_len = 0;

    for (int i = 0; i < arg_number; i++) {
        if (command[0] != ' ' || command[1] != '"')
            return (NULL);
        command = command + 2;
        for (arg_len = 0; command[arg_len] && command[arg_len] != '"';
        arg_len++);
        if (!command[arg_len])
            return (NULL);
        args[i] = malloc(sizeof(char) * (arg_len + 1));
        if (!args[i])
            return (NULL);
        strncpy(args[i], command, arg_len);
        command = command + arg_len + 1;
    }
    if (command[0])
        return (NULL);
    args[arg_number] = NULL;
    return (args);
}

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

char **fill_command_arguments(char *command, char *name)
{
    char **args = NULL;
    const cli_command_t *cmd = get_cli_command_by_name(name);
    int i = 0;

    if (!cmd)
        return (NULL);
    for (i = 0; cmd->arguments && cmd->arguments[i]; i++);
    if (i)
        args = get_arguments(command, i);
    return (args);
}