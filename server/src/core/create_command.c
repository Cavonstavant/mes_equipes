/*
** EPITECH PROJECT, 2022
** Project
** File description:
** create_command
*/

/// \file server/src/create_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"
#include "upper_component_adding.h"

///
/// \brief Create a new team
///
/// \param arguments Arguments for the creation
/// \param user User info
/// \param serv Server info
/// \return true When operation succeed
/// \return false When operation failed
///
static bool command_create_team(char **arguments, user_list_t *user,
server_data_t *serv)
{
    if (find_team_by_name(serv->wrapper, arguments[0])) {
        print_retcode(320, NULL, user->user_peer);
        return true;
    }
    if (wrapper_adding_team(serv->wrapper, (team_creation_t) {
        arguments[0],
        arguments[1]
    }) == false) {
        print_retcode(503, NULL, user->user_peer);
        return true;
    }
    print_retcode(200, NULL, user->user_peer);
    server_event_team_created(find_team_by_name(serv->wrapper,
    arguments[0])->uuid.repr, arguments[0],
    user->user_uuid->uuid.repr);
    return true;
}

///
/// \brief Create a new chan
///
/// \param arguments Arguments for the creation
/// \param user User info
/// \param serv Server info
/// \return true When operation succeed
/// \return false When operation failed
///
static bool command_create_chan(char **arguments, user_list_t *user,
server_data_t *serv)
{
    if (find_channel_by_name_exc(serv->wrapper, arguments[0], user->loc)) {
        print_retcode(320, NULL, user->user_peer);
        return true;
    }
    if (!wrapper_new_channel_to_team(serv->wrapper, (channel_creation_t) {
        arguments[0],
        arguments[1],
        user->loc
    }, user->loc)) {
        print_retcode(503, NULL, user->user_peer);
        return true;
    }
    print_retcode(200, NULL, user->user_peer);
    server_event_channel_created(user->loc->uuid.repr,
    find_channel_by_name_exc(serv->wrapper, arguments[0],
    user->loc)->uuid.repr, arguments[0]);
    return true;
}

///
/// \brief Create a new thread
///
/// \param arguments Arguments for the creation
/// \param user User info
/// \param serv Server info
/// \return true When operation succeed
/// \return false When operation failed
///
static bool command_create_thread(char **arguments, user_list_t *user,
server_data_t *serv)
{
    if (find_thread_by_name_exc(serv->wrapper, arguments[0], user->loc)) {
        print_retcode(320, NULL, user->user_peer);
        return true;
    }
    if (!wrapper_new_thread_to_channel(serv->wrapper, (thread_creation_t) {
        arguments[0],
        arguments[1],
        user->user_uuid,
        user->loc
    }, user->loc)) {
        print_retcode(503, NULL, user->user_peer);
        return true;
    }
    print_retcode(200, NULL, user->user_peer);
    server_event_thread_created(user->loc->uuid.repr,
    find_thread_by_name_exc(serv->wrapper, arguments[0],
    user->loc)->uuid.repr, user->user_uuid->uuid.repr,
    arguments[0], arguments[1]);
    return true;
}

///
/// \brief Create a new reply
///
/// \param arguments Arguments for the creation
/// \param user User info
/// \param serv Server info
/// \return true When operation succeed
/// \return false When operation failed
///
static bool command_create_reply(char **arguments, user_list_t *user,
server_data_t *serv)
{
    if (!wrapper_new_comment_to_thread(serv->wrapper, (comment_creation_t) {
        arguments[0],
        user->loc,
        user->user_uuid
    }, user->loc)) {
        print_retcode(503, NULL, user->user_peer);
        return true;
    }
    print_retcode(200, NULL, user->user_peer);
    server_event_reply_created(user->loc->uuid.repr,
    user->user_uuid->uuid.repr, arguments[0]);
    return true;
}

bool command_create(cli_command_t *command,
user_list_t *user, server_data_t *serv)
{
    my_uuid_prefix_t type = my_uuid_get_prefix(&user->loc->uuid);

    if (!user->is_auth) {
        print_retcode(401, NULL, user->user_peer);
        return true;
    }
    if (user->loc == NULL)
        return command_create_team(command->arguments, user, serv);
    if (type == MY_UUID_PREFIX_TEAM)
        return command_create_chan(command->arguments, user, serv);
    if (type == MY_UUID_PREFIX_CHANNEL)
        return command_create_thread(command->arguments, user, serv);
    if (type == MY_UUID_PREFIX_THREAD)
        return command_create_reply(command->arguments, user, serv);
    return true;
}
