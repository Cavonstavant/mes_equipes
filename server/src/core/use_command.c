/*
** EPITECH PROJECT, 2022
** Project
** File description:
** use_command
*/

/// \file server/src/core/use_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"

/// \brief Change the user loc to a team
/// \param uuid Uuid of the team to go
/// \param serv Server info
/// \param user User info
/// \param print Last command of use
/// \return true When operation succeed
/// \return false When operation failed
static bool command_go_team(my_uuid_t *uuid, server_data_t *serv,
user_list_t *user, bool print)
{
    if (!uuid || !wrapper_find_team(serv->wrapper, uuid))
        return print_retcode(311, cretcodes((char *[]) {
        "/use TEM", uuid->uuid.repr, NULL}), user->user_peer, false);
    if (!user_is_sub_to_team(serv->wrapper, user->user_uuid, uuid))
        return print_retcode(322, uuid->uuid.repr, user->user_peer, false);
    user->loc = uuid;
    if (print)
        print_retcode(200, NULL, user->user_peer, true);
    return true;
}

/// \brief Change the user loc to a chan
/// \param uuid Uuid of the chan to go
/// \param serv Server info
/// \param user User info
/// \param print Last command of use
/// \return true When operation succeed
/// \return false When operation failed
static bool command_go_to_chan(my_uuid_t *uuid, server_data_t *serv,
user_list_t *user, bool print)
{
    if (!uuid || !wrapper_find_channel_tm(serv->wrapper, uuid, user->loc))
        return print_retcode(311, cretcodes((char *[]) {
        "/use CHA", uuid->uuid.repr, NULL}), user->user_peer, false);
    user->loc = uuid;
    if (print)
        print_retcode(200, NULL, user->user_peer, true);
    return true;
}

/// \brief Change the user loc to a thread
/// \param uuid Uuid of the thread to go
/// \param serv Server info
/// \param user User info
/// \param print Last command of use
/// \return true When operation succeed
/// \return false When operation failed
static bool command_go_to_thread(my_uuid_t *uuid, server_data_t *serv,
user_list_t *user, bool print)
{
    if (!uuid || !wrapper_find_thread_tm(serv->wrapper, uuid, user->loc))
        return print_retcode(311, cretcodes((char *[]) {
        "/use THR", uuid->uuid.repr, NULL}), user->user_peer, false);
    user->loc = uuid;
    if (print)
        print_retcode(200, NULL, user->user_peer, true);
    return true;
}

/// \brief Change the user loc to a object
/// \param uuid Uuid of the object to go
/// \param serv Server info
/// \param user User info
/// \param print Last command of use
/// \return true When operation succeed
/// \return false When operation failed
static bool command_go_next(char *uuid, user_list_t *user,
server_data_t *serv, bool print)
{
    my_uuid_prefix_t type;

    if (!my_uuid_fstring(uuid, serv->wrapper))
        return print_retcode(311, cretcodes((char *[]) {
        "/use", ((user->loc) ? user->loc->uuid.repr : "NULL"),
        uuid, NULL}), user->user_peer, false);
    type = my_uuid_get_prefix(&(my_uuid_fstring(uuid,
    serv->wrapper)->uuid));
    if (type == MY_UUID_PREFIX_TEAM)
        return command_go_team(my_uuid_fstring(uuid, serv->wrapper),
        serv, user, print);
    if (type == MY_UUID_PREFIX_CHANNEL)
        return command_go_to_chan(my_uuid_fstring(uuid, serv->wrapper),
        serv, user, print);
    if (type == MY_UUID_PREFIX_THREAD)
        return command_go_to_thread(my_uuid_fstring(uuid, serv->wrapper),
        serv, user, print);
    return print_retcode(311, cretcodes((char *[]) {
    "/use", uuid, NULL}), user->user_peer, false);
}

bool command_use(cli_command_t *command,
user_list_t *user, server_data_t *server_data)
{
    int command_number = 0;

    if (command->arguments)
        for (; command->arguments[command_number] != NULL; command_number++);
    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (command_number == 0)
        return command_use_empty(user, true);
    if (command_number == 1)
        return command_go_next(command->arguments[0], user, server_data, true);
    if (command_number == 2)
        return command_go_next(command->arguments[0], user, server_data, false)
        && command_go_next(command->arguments[1], user, server_data, true);
    return command_use_empty(user, false)
    && command_go_next(command->arguments[0], user, server_data, false)
    && command_go_next(command->arguments[1], user, server_data, false)
    && command_go_next(command->arguments[2], user, server_data, true);
}
