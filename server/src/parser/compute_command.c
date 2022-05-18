/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command
*/

/// \file server/src/parser/compute_command.c

#include <stdio.h>
#include "cli_commands.h"

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
    command = command + i;
    return (name);
}

char **get_arguments(char *command, int arg_number)
{
    int j = 0;
    char **args = malloc(sizeof(char *) * i);

    if (!args)
        return (NULL);
    for (int i = 0; i < arg_number; i++) {
        if (command[0] == ' ' && command[1] == '"')
            command = command + 2;
        else
            return (NULL);
        for (j = 0; command[j] && command[j] != '"'; j++);
        if (!command[j])
            return (NULL);
        args[i] = malloc(sizeof(char) * j);
        if (!args[i])
            return (NULL);
        strncpy(args[i], command, j);
        command = command + j;
    }
    return (args);
}

char **fill_command_arguments(char *command, char *name)
{
    char **args = NULL;
    cli_command_t *cmd = get_cli_command_by_name(name);
    int i = 0;

    if (!cmd)
        return (NULL);
    for (i = 0; cmd.arguments && cmd.arguments[i]; i++);
    if (i)
        args = get_arguments(command, i);
    return (args);
}

cli_command_t *convert_command_to_structure(char *command)
{
    cli_command_t *cli_command = {NULL, NULL, NULL};

    if (!command)
        return (NULL);
    cli_command.name = get_command_name(command);
    if (!cli_command.name)
        return (NULL);
    cli_command.arguments = fill_command_arguments(command, cli_command.name);
    return (cli_command);
}

int compute_command(char *command)
{
    cli_command_t *command = convert_command_to_structure(command);

    if (command == NULL)
        return (-1);
    if (call_command(command) < 0)
        return (-1)
    free(command);
    return (0);
}
