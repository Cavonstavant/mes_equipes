/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** call_command
*/

#include "cli_commands.h"
#include <stddef.h>

int call_command(char **arguments)
{
    cli_command_t *commands = get_cli_commands();
    void *retval = NULL;

    for (int i = 0; i < 14; i++) {
        if (strcmp(arguments[0], commands[i].name) == 0)
            retval = commands[i].function(NULL);
    }
    return (0);
}