/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** call_command
*/

/// \file server/src/core/call_command.c

#include "cli_commands.h"
#include "rcodes.h"

/// \brief The number of command available.
/// \param args The arguments of the command.
/// \return The number of arguments.
static int get_nb_arguments(char **args)
{
    int i = 0;

    for (i = 0; args && args[i]; i++);
    return (i);
}

/// \brief Check if the command is valid.
/// \param cmd The command reference to check.
/// \param command The command to check.
/// \param users The user list.
/// \return true if the command is valid, false otherwise.
static bool check_arguments_validity(const cli_command_t *cmd,
cli_command_t *command,
user_list_t *users)
{
    int i = get_nb_arguments(cmd->arguments);
    int j = get_nb_arguments(command->arguments);

    if (strcmp(command->name, "/use") == 0)
        return (true);
    if (strcmp(command->name, "/subscribed") == 0)
        return (true);
    if (strcmp(command->name, "/create") == 0)
        return (true);
    if (j != i)
        return print_retcode(510, NULL, users->user_peer, false);
    return (true);
}

int call_command(cli_command_t *command, user_list_t *users,
server_data_t *server_data)
{
    const cli_command_t *cmd = get_cli_command_by_name(command->name);

    if (!cmd) {
        return (-1);
    }
    if (check_arguments_validity(cmd, command, users) == false)
        return (-1);
    if (!cmd->function(command, users, server_data))
        return (-1);
    return (0);
}
