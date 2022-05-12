/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** call_command
*/

/// \file server/src/parser/call_commands.c

#include "cli_commands.h"
#include <stddef.h>
#include <stdbool.h>

int call_command(char **arguments)
{
    cli_command_t *commands = get_cli_commands();
    void *retval = NULL;
    bool command_found = false;

    for (int i = 0; i < COMMAND_NUMBER; i++) {
        if (strcmp(arguments[0], commands[i].name) == 0) {
            retval = commands[i].function(NULL);
            command_found = true;
        }
    }
    if (!command_found) {
        printf("Command not found: %s\n", arguments[0]);
        return (-1);
    }
    return (0);
}
