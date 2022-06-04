/*
** EPITECH PROJECT, 2022
** Project
** File description:
** subscribe_command
*/

/// \file server/src/core/subscribe_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"

bool command_subscribe(cli_command_t *cmd,
user_list_t *user, server_data_t *data)
{
    my_uuid_t *team = my_uuid_fstring(cmd->arguments[0], data->wrapper);

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (!team || wrapper_find_team(data->wrapper, team) == OBJECT_NOT_FOUND)
        return print_retcode(311, cretcodes((char *[]) {
        cmd->name, cmd->arguments[0], NULL}), user->user_peer, true);
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
    if (!team || wrapper_find_team(data->wrapper, team) == OBJECT_NOT_FOUND)
        return print_retcode(311, cretcodes((char *[]) {
        cmd->name, cmd->arguments[0], NULL}), user->user_peer, true);
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

/// \brief Command list my
/// \param user User list
/// \param srv Server data
/// \return true When operation succeed
static bool command_list_my(user_list_t *user, server_data_t *srv)
{
    child_list_t list = get_subscribed_team_of_user(srv->wrapper,
    user->user_uuid);
    char **args = NULL;
    team_t *team = NULL;

    if (list.size == 0)
        return print_retcode(310, NULL, user->user_peer, false);
    args = malloc(sizeof(char *) * (list.size * 3 + 1));
    if (args == NULL)
        return false;
    for (int i = 0; i < list.size; i++) {
        team = wrapper_find_team(srv->wrapper, list.list[i]);
        args[i * 3] = team->uuid->uuid.repr;
        args[i * 3 + 1] = team->name;
        args[i * 3 + 2] = team->description;
    }
    args[list.size * 3] = NULL;
    return print_retcode(206, cretcodes(args), user->user_peer, true);
}

/// \brief Command list their
/// \param user User list
/// \param srv Server data
/// \param uuid UUID
/// \return true When operation succeed
static bool command_list_their(user_list_t *user, server_data_t *srv,
my_uuid_t *uuid)
{
    child_list_t list = get_subscribed_user_of_team(srv->wrapper, uuid);
    char **args = NULL;
    user_t *auser = NULL;

    if (list.size == 0)
        return print_retcode(310, NULL, user->user_peer, false);
    args = malloc(sizeof(char *) * (list.size * 3 + 1));
    if (args == NULL)
        return false;
    for (int i = 0; i < list.size; i++) {
        auser = wrapper_find_user(srv->wrapper, list.list[i]);
        args[i * 3] = auser->uuid->uuid.repr;
        args[i * 3 + 1] = auser->name;
        args[i * 3 + 2] = (auser->status) ? "1" : "0";
    }
    args[list.size * 3] = NULL;
    return print_retcode(206, cretcodes(args), user->user_peer, true);
}

bool command_subscribed(cli_command_t *cmd,
user_list_t *user, server_data_t *data)
{
    my_uuid_t *uuid = NULL;

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (!cmd->arguments || !cmd->arguments[0])
        return command_list_my(user, data);
    else {
        uuid = my_uuid_fstring(cmd->arguments[0], data->wrapper);
        if (!uuid || !wrapper_find_team(data->wrapper, uuid))
            return print_retcode(311, cretcodes((char *[]) {
            cmd->name, cmd->arguments[0], NULL}), user->user_peer, false);
        return command_list_their(user, data, uuid);
    };
}
