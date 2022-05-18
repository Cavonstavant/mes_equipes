/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** call_command
*/

#include "cli_commands.h"

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
