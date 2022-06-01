/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** call_command
*/

/// \file server/src/core/call_command.c

#include "cli_commands.h"
#include "rcodes.h"

static int get_nb_arguments(char **args)
{
    int i = 0;

    for (i = 0; args && args[i]; i++);
    return (i);
}

static bool check_arguments_validity(const cli_command_t *cmd, cli_command_t *command,
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
    if (j != i) {
        print_retcode(510, NULL, users->user_peer);
        return (false);
    }
    return (true);
}

/// /!\ This function doesn't call the function actually, because the function
/// are not implemented yet.
/// /!\ The argument to be passed as parameter in the function to be called
/// must be contains the arguments of the command, and an object to be use
/// to ask a write on the client.

int call_command(cli_command_t *command, user_list_t *users,
server_data_t *server_data)
{
    const cli_command_t *cmd = get_cli_command_by_name(command->name);

    if (!cmd) {
        return (-1);
    }
    if (check_arguments_validity(cmd, command, users) == false)
        return (-1);
    cmd->function(command, users, server_data);
    return (0);
}
