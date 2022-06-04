/*
** EPITECH PROJECT, 2022
** Project
** File description:
** auth_command
*/

/// \file server/src/core/auth_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"
#include "upper_component_adding.h"

///
/// \brief Edit the status of the logged out user
///
/// \param serv Server informations
/// \param user User informations
/// \return true When operation succeed
/// \return false When operation failed
///
static bool command_logout_status(server_data_t *serv, user_list_t *user)
{
    for (size_t i = 0; i < serv->active_user_n; i++) {
        if (serv->active_users[i]->disconnected == CONNECTED &&
            serv->active_users[i]->is_auth && my_uuid_cmp(
            serv->active_users[i]->user_uuid, user->user_uuid))
            return true;
    }
    return false;
}

bool command_logout(cli_command_t *command __attribute__((unused)),
user_list_t *user, server_data_t *serv)
{
    user->disconnected = TO_LOGOUT;
    if (user->is_auth) {
        print_retcode(203, cretcodes((char *[]) {user->user_uuid->uuid.repr,
        wrapper_find_user(serv->wrapper, user->user_uuid)->name, NULL
        }), user->user_peer, true);
        send_users_event_logout(serv, 602, (char *[]) {
        user->user_uuid->uuid.repr + 4, wrapper_find_user(serv->wrapper,
        user->user_uuid)->name, NULL}, user->user_peer->sock_fd);
        server_event_user_logged_out(user->user_uuid->uuid.repr + 4);
    } else
        print_retcode(203, "NONE", user->user_peer, true);
    if (command_logout_status(serv, user))
        return true;
    if (user->is_auth)
        user_edit_status(wrapper_find_user(serv->wrapper,
        user->user_uuid), false);
    return true;
}

bool command_login(cli_command_t *command,
user_list_t *user, server_data_t *server_data)
{
    char *uname = command->arguments[0];
    my_uuid_t *user_uuid = find_user_by_name(server_data->wrapper, uname);

    if (user_uuid != OBJECT_NOT_FOUND) {
        wrapper_find_user(server_data->wrapper, user_uuid)->status = true;
        user->user_uuid = user_uuid;
    } else {
        if (wrapper_adding_user(server_data->wrapper, (user_creation_t) {uname,
        true}) == false)
            return false;
        user->user_uuid = find_user_by_name(server_data->wrapper, uname);
        server_event_user_created(user->user_uuid->uuid.repr + 4, uname);
    }
    user->is_auth = true;
    send_users_event(server_data, 601, (char *[]) {
    user->user_uuid->uuid.repr + 4, uname, NULL});
    server_event_user_logged_in(user->user_uuid->uuid.repr + 4);
    return true;
}
