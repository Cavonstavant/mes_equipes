/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** call_command
*/

#include "cli_commands.h"

/// /!\ This function doesn't call the function actually, because the function
/// are not implemented yet.
/// /!\ The argument to be passed as parameter in the function to be called
/// must be contains the arguments of the command, and an object to be use
/// to ask a write on the client.

int call_command(cli_command_t *command)
{
    const cli_command_t *cmd = get_cli_command_by_name(command->name);
    int i = 0;
    int j = 0;

    if (!cmd)
        return (-1);
    for (i = 0; cmd->arguments && cmd->arguments[i]; i++);
    for (j = 0; command->arguments && command->arguments[j]; j++);
    if (j != i) {
        // print_retcode(510);
        return (-1);
    }
    return (0);
}
