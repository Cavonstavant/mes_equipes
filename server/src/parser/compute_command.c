/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command
*/

/// \file server/src/parser/compute_command.c

#include <stdio.h>
#include "cli_commands.h"

static void free_args(char **args)
{
    int index = 0;

    if (args) {
        while (args[index]) {
            free(args[index]);
            index++;
        }
        free(args);
    }
}

int compute_command(char *command)
{
    int nb_args = check_command(command); // check command, return -1 or nb_args
    char **args = NULL;

    if (nb_args < 0)
        return (-1);
    args = split_command(command); // split in args, return NULL or args array
    if (!args)
        return (-1);
    if (call_command(args) < 0) {
        free_args(args);
        return (-1); // call command, return -1 or 0
    }
    free_args(args);
    return (0);
}
