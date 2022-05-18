/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command
*/

/// \file server/src/parser/compute_command.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli_commands.h"

#include <stdio.h>

char *get_command_name(char *command)
{
    char *name = NULL;
    int i = 0;

    while (command[i] && command[i] != ' ')
        i++;
    name = malloc(sizeof(char) * i);
    if (!name)
        return (NULL);
    strncpy(name, command, i);
    return (name);
}

char *skip_command(char *command)
{
    int i = 0;

    while (command && command[i] && command[i] != ' ')
        i++;
    if (!command || !command[i])
        return (NULL);
    command = command + i;
    return (command);
}

char **fill_arguments(char *command, int arg_number, char **args)
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
        strncpy(args[i], command, arg_len);
        command = command + arg_len + 1;
    }
    if (command[0])
        return (NULL);
    args[arg_number] = NULL;
    return (args);
}

char **get_arguments(char *command, int arg_number)
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

cli_command_t *convert_command_to_structure(char *command)
{
    cli_command_t *cli_command = malloc(sizeof(cli_command_t));

    if (!cli_command)
        return (NULL);
    cli_command->name = NULL;
    cli_command->arguments = NULL;
    cli_command->function = NULL;
    if (!command)
        return (NULL);
    cli_command->name = get_command_name(command);
    if (!cli_command->name)
        return (NULL);
    cli_command->arguments =
    fill_command_arguments(command, cli_command->name);
    return (cli_command);
}

int call_command(cli_command_t *command)
{
    const cli_command_t *cmd = get_cli_command_by_name(command->name);
    int i = 0;
    int j = 0;

    if (!cmd)
        return (-1);
    for (i = 0; cmd->arguments && cmd->arguments[i]; i++);
    for (j = 0; command->arguments && command->arguments[j]; j++);
    if (j != i)
        return (-1);
    return (0);
}

int compute_command(char *command)
{
    char *tmp = command;
    cli_command_t *cmd = convert_command_to_structure(command);

    if (cmd == NULL) {
        return (-1);
    }
    if (call_command(cmd) < 0) {
        return (-1);
    }
    free(tmp);
    return (0);
}
