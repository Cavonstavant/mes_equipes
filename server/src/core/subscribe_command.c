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

bool command_subscribe(cli_command_t *command,
user_list_t *user, server_data_t *serv_data)
{
    my_uuid_t *team = my_uuid_from_string(command->arguments[0]);

    if (!user->is_auth) {
        print_retcode(401, NULL, user->user_peer);
        return true;
    }
    if (wrapper_find_team(serv_data->wrapper, team) == OBJECT_NOT_FOUND) {
        print_retcode(311, NULL, user->user_peer);
        return true;
    }
    if (user_is_sub_to_team(serv_data->wrapper, user->user_uuid,
    team) == true) {
        print_retcode(321, (char *[]){team->uuid.repr}, user->user_peer);
        return true;
    }
    wrapper_user_join_team(serv_data->wrapper, user->user_uuid,
    team);
    print_retcode(200, NULL, user->user_peer);
    server_event_user_subscribed(team->uuid.repr, user->user_uuid->uuid.repr);
    return true;
}

bool command_unsubscribe(cli_command_t *command,
user_list_t *user, server_data_t *serv_data)
{
    my_uuid_t *team = my_uuid_from_string(command->arguments[0]);

    if (!user->is_auth) {
        print_retcode(401, NULL, user->user_peer);
        return true;
    }
    if (wrapper_find_team(serv_data->wrapper, team) == OBJECT_NOT_FOUND) {
        print_retcode(311, NULL, user->user_peer);
        return true;
    }
    if (user_is_sub_to_team(serv_data->wrapper, user->user_uuid,
    team) == false) {
        print_retcode(322, (char *[]){team->uuid.repr}, user->user_peer);
        return true;
    }
    wrapper_user_leave_team(serv_data->wrapper, user->user_uuid, team);
    print_retcode(200, NULL, user->user_peer);
    server_event_user_unsubscribed(user->user_uuid->uuid.repr,
    team->uuid.repr);
    return true;
}