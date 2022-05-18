/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command
*/

/// \file server/src/parser/compute_command.c

#include <stdlib.h>
#include "cli_commands.h"

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
