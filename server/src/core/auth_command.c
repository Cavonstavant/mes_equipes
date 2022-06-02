/*
** EPITECH PROJECT, 2022
** Project
** File description:
** auth_command
*/

/// \file server/src/auth_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"
#include "upper_component_adding.h"

bool command_logout(cli_command_t *command,
user_list_t *user_info, server_data_t *server_data)
{
    (void) command;
    print_retcode(203, "Michel", user_info->user_peer);
    user_info->disconnected = TO_LOGOUT;
    if (user_info->is_auth)
        server_event_user_logged_out(user_info->user_uuid->uuid.repr + 4);
    for (size_t i = 0; i < server_data->active_user_n; i++) {
        if (server_data->active_users[i]->disconnected == CONNECTED &&
            server_data->active_users[i]->is_auth && my_uuid_cmp(
                server_data->active_users[i]->user_uuid, user_info->user_uuid
            ))
            return true;
    }
    if (user_info->is_auth)
        user_edit_status(wrapper_find_user(server_data->wrapper,
        user_info->user_uuid), false);
    return true;
}

bool command_login(cli_command_t *command,
user_list_t *user_info, server_data_t *server_data)
{
    char *uname = command->arguments[0];
    my_uuid_t *user_uuid = find_user_by_name(server_data->wrapper, uname);

    if (user_uuid != OBJECT_NOT_FOUND) {
        print_retcode(201, uname, user_info->user_peer);
        user_info->user_uuid = user_uuid;
    } else {
        if (wrapper_adding_user(server_data->wrapper, (user_creation_t) {
            uname,
            true
        }) == false)
            return true;
        print_retcode(202, uname, user_info->user_peer);
        user_info->user_uuid =
        find_user_by_name(server_data->wrapper, uname);
        server_event_user_created(user_info->user_uuid->uuid.repr + 4, uname);
    }
    user_info->is_auth = true;
    server_event_user_logged_in(user_info->user_uuid->uuid.repr + 4);
    return true;
}