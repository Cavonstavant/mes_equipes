/*
** EPITECH PROJECT, 2022
** Project
** File description:
** info_command
*/

/// \file server/src/core/info_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"

/// \brief Display info of the current user
/// \param user User info
/// \param serv Serv info
/// \return true When operation succeed
/// \return false When operation faield
static bool command_info_user(user_list_t *user, server_data_t *serv)
{
    user_t *auser = wrapper_find_user(serv->wrapper, user->user_uuid);

    return print_retcode(211, cretcodes((char *[]) {
        auser->uuid->uuid.repr,
        auser->name,
        ((auser->status) ? "1" : "0"),
        NULL
    }), user->user_peer, true);
}

/// \brief Display info of the current loc
/// \param user User info
/// \param serv Serv info
/// \param uuid Location uuid
/// \return true When operation succeed
/// \return false When operation failed
static bool command_info_team(user_list_t *user, server_data_t *serv,
my_uuid_t *uuid)
{
    team_t *team = wrapper_find_team(serv->wrapper, uuid);

    return print_retcode(211, cretcodes((char *[]) {
        team->uuid->uuid.repr,
        team->name,
        team->description,
        NULL
    }), user->user_peer, true);
}

/// \brief Display info of the current loc
/// \param user User info
/// \param serv Serv info
/// \param uuid Location uuid
/// \return true When operation succeed
/// \return false When operation failed
static bool command_info_chan(user_list_t *user, server_data_t *serv,
my_uuid_t *uuid)
{
    channel_t *channel = wrapper_find_channel(serv->wrapper, uuid);

    return print_retcode(211, cretcodes((char *[]) {
        channel->uuid->uuid.repr,
        channel->name,
        channel->description,
        NULL
    }), user->user_peer, true);
}

/// \brief Display info of the current loc
/// \param user User info
/// \param serv Serv info
/// \param uuid Location uuid
/// \return true When operation succeed
/// \return false When operation failed
static bool command_info_thread(user_list_t *user, server_data_t *serv,
my_uuid_t *uuid)
{
    thread_t *thread = wrapper_find_thread(serv->wrapper, uuid);

    return print_retcode(211, cretcodes((char *[]) {
        thread->uuid->uuid.repr,
        thread->author->uuid.repr,
        thread_get_time(thread),
        thread->name,
        thread->body,
        NULL
    }), user->user_peer, true);
}

bool command_info(cli_command_t *cmd,
user_list_t *user, server_data_t *data)
{
    my_uuid_prefix_t type = my_uuid_get_prefix(&user->loc->uuid);

    (void) cmd;
    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (user->loc == NULL)
        return command_info_user(user, data);
    if (type == MY_UUID_PREFIX_TEAM)
        return command_info_team(user, data, user->loc);
    if (type == MY_UUID_PREFIX_CHANNEL)
        return command_info_chan(user, data, user->loc);
    if (type == MY_UUID_PREFIX_THREAD)
        return command_info_thread(user, data, user->loc);
    return false;
}
