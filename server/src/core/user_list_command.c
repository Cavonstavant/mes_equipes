/*
** EPITECH PROJECT, 2022
** Project
** File description:
** user_list_command
*/

/// \file server/src/core/use_list_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"

bool command_users(cli_command_t *cmd __attribute__((unused)),
user_list_t *user, server_data_t *data)
{
    char **args = NULL;

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, false);
    if (data->wrapper->user_n == 0)
        return print_retcode(310, NULL, user->user_peer, false);
    args = malloc(sizeof(char *) * (data->wrapper->user_n * 3 + 1));
    if (args == NULL)
        return false;
    for (int i = 0; i < data->wrapper->user_n; i++) {
        args[i * 3] = data->wrapper->users[i]->uuid->uuid.repr;
        args[i * 3 + 1] = data->wrapper->users[i]->name;
        args[i * 3 + 2] = ((data->wrapper->users[i]->status) ? "1" : "0");
    }
    args[data->wrapper->user_n * 3] = NULL;
    print_retcode(204, cretcodes(args), user->user_peer, true);
    free(args);
    return true;
}

bool command_user(cli_command_t *cmd,
user_list_t *user, server_data_t *data)
{
    user_t *users = NULL;

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, false);
    users = wrapper_find_user(data->wrapper,
    my_uuid_fstring(cmd->arguments[0], data->wrapper));
    if (!user)
        return print_retcode(311, cretcodes((char *[]) {
        cmd->name, cmd->arguments[0], NULL}), user->user_peer, false);
    return print_retcode(211, cretcodes((char *[]) {users->uuid->uuid.repr,
    users->name, ((users->status) ? "1" : "0"), NULL}), user->user_peer, true);
}
