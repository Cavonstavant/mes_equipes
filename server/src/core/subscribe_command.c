/*
** EPITECH PROJECT, 2022
** Project
** File description:
** subscribe_command
*/

/// \file server/src/subscribe_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"

bool command_subscribe(cli_command_t *cmd,
user_list_t *user, server_data_t *data)
{
    my_uuid_t *team = my_uuid_fstring(cmd->arguments[0], data->wrapper);

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (wrapper_find_team(data->wrapper, team) == OBJECT_NOT_FOUND)
        return print_retcode(311, team->uuid.repr, user->user_peer, true);
    if (user_is_sub_to_team(data->wrapper, user->user_uuid,
    team) == true) {
        return print_retcode(321, team->uuid.repr, user->user_peer, true);
    }
    wrapper_user_join_team(data->wrapper, user->user_uuid, team);
    server_event_user_subscribed(team->uuid.repr + 4,
    user->user_uuid->uuid.repr + 4);
    return print_retcode(219, cretcodes((char *[]) {user->user_uuid->uuid.repr,
    team->uuid.repr, NULL}), user->user_peer, true);
}

bool command_unsubscribe(cli_command_t *cmd,
user_list_t *user, server_data_t *data)
{
    my_uuid_t *team = my_uuid_fstring(cmd->arguments[0], data->wrapper);

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (wrapper_find_team(data->wrapper, team) == OBJECT_NOT_FOUND)
        return print_retcode(311, team->uuid.repr, user->user_peer, true);
    if (user_is_sub_to_team(data->wrapper, user->user_uuid,
    team) == false) {
        return print_retcode(322, team->uuid.repr + 4, user->user_peer, true);
    }
    wrapper_user_leave_team(data->wrapper, user->user_uuid, team);
    server_event_user_unsubscribed(user->user_uuid->uuid.repr + 4,
    team->uuid.repr + 4);
    return print_retcode(220, cretcodes((char *[]) {user->user_uuid->uuid.repr,
    team->uuid.repr, NULL}), user->user_peer, true);
}