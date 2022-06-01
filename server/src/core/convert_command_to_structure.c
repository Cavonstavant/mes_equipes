/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** convert_command_to_structure
*/

/// \file server/src/core/convert_command_to_structure.c

#include "cli_commands.h"
#include "rcodes.h"
#include <stdlib.h>
#include <string.h>

/// \brief Get the command name from the command.
/// \param char *The command.
/// \return char *The command name.
static char *get_command_name(char *command)
{
    char *name = NULL;
    int i = 0;

    while (command[i] && command[i] != ' ' && command[i] != '\n')
        i++;
    name = malloc(sizeof(char) * (i + 1));
    if (!name)
        return (NULL);
    strncpy(name, command, i);
    name[i] = '\0'; /// WARNING THOMAS CHECK LAST CHAR IS \N
    return (name);
}

cli_command_t *convert_command_to_structure(char *command, user_list_t *users)
{
    cli_command_t *cli_command = malloc(sizeof(cli_command_t));

    if (!cli_command)
        return (NULL);
    cli_command->name = NULL;
    cli_command->arguments = NULL;
    cli_command->function = NULL;
    if (!command) {
        print_retcode(500, NULL, users->user_peer);
        return (NULL);
    }
    cli_command->name = get_command_name(command);
    if (!cli_command->name) {
        print_retcode(500, NULL, users->user_peer);
        return (NULL);
    }
    cli_command->arguments =
    fill_command_arguments(command, cli_command->name, users);
    return (cli_command);
}
