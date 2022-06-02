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
    my_uuid_t *new = NULL;

    if (find_team_by_name(serv->wrapper, arguments[0]))
        return print_retcode(320, NULL, user->user_peer, true);
    if (wrapper_adding_team(serv->wrapper, (team_creation_t) {
        arguments[0],
        arguments[1]
    }) == false) {
        return print_retcode(503, NULL, user->user_peer, true);
    }
    new = find_team_by_name(serv->wrapper, arguments[0]);
    server_event_team_created(new->uuid.repr + 4, arguments[0],
    user->user_uuid->uuid.repr + 4);
    return print_retcode(215, cretcodes((char *[]) {new->uuid.repr,
    arguments[0], arguments[1], NULL}), user->user_peer, true);
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
    my_uuid_t *new = NULL;

    if (find_channel_by_name_exc(serv->wrapper, arguments[0], user->loc))
        return print_retcode(320, NULL, user->user_peer, true);
    if (!wrapper_new_channel_to_team(serv->wrapper, (channel_creation_t) {
        arguments[0],
        arguments[1],
        user->loc
    }, user->loc)) {
        return print_retcode(503, NULL, user->user_peer, true);
    }
    new = find_channel_by_name_exc(serv->wrapper, arguments[0], user->loc);
    server_event_channel_created(user->loc->uuid.repr + 4,
    new->uuid.repr + 4, arguments[0]);
    return print_retcode(216, cretcodes((char *[]) {new->uuid.repr,
    arguments[0], arguments[1], NULL}), user->user_peer, true);
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
    thread_t *new = NULL;

    if (find_thread_by_name_exc(serv->wrapper, arguments[0], user->loc))
        return print_retcode(320, NULL, user->user_peer, true);
    if (!wrapper_new_thread_to_channel(serv->wrapper, (thread_creation_t) {
        arguments[0],
        arguments[1],
        user->user_uuid,
        user->loc
    }, user->loc)) {
        return print_retcode(503, NULL, user->user_peer, true);
    }
    new = wrapper_find_thread(serv->wrapper, 
    find_thread_by_name_exc(serv->wrapper, arguments[0], user->loc));
    server_event_thread_created(user->loc->uuid.repr + 4,
    new->uuid->uuid.repr + 4, user->user_uuid->uuid.repr + 4,
    arguments[0], arguments[1]);
    return print_retcode(217, cretcodes((char *[]) {new->uuid->uuid.repr,
    user->user_uuid->uuid.repr, thread_get_time(new), arguments[0],
    arguments[1], NULL}), user->user_peer, true);
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
    comment_t *new = NULL;

    if (!wrapper_new_comment_to_thread(serv->wrapper, (comment_creation_t) {
        arguments[0],
        user->loc,
        user->user_uuid
    }, user->loc)) {
        return print_retcode(503, NULL, user->user_peer, true);
    }
    new = serv->wrapper->comments[serv->wrapper->comment_n - 1];
    server_event_reply_created(user->loc->uuid.repr + 4,
    user->user_uuid->uuid.repr + 4, arguments[0]);
    return print_retcode(218, cretcodes((char *[]) {new->thread->uuid.repr,
    new->author->uuid.repr, comment_get_time(new), arguments[0], NULL}),
    user->user_peer, true);
}

bool command_create(cli_command_t *command,
user_list_t *user, server_data_t *serv)
{
    my_uuid_prefix_t type = my_uuid_get_prefix(&user->loc->uuid);

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
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
