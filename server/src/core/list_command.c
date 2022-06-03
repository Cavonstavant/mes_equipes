/*
** EPITECH PROJECT, 2022
** Project
** File description:
** list_command
*/

/// \file server/src/list_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"

///
/// \brief List all the team
///
/// \param user User info
/// \param serv Serv info
/// \return true When operation succeed
/// \return false When operation faield
///
static bool command_list_team(user_list_t *user, server_data_t *serv)
{
    char **args = NULL;
    team_t **list = serv->wrapper->teams;

    if (serv->wrapper->team_n == 0)
        return print_retcode(310, NULL, user->user_peer, false);
    args = malloc(sizeof(char *) * (serv->wrapper->team_n * 3 + 1));
    if (args == NULL)
        return false;
    for (int i = 0; i < serv->wrapper->team_n; i++) {
        args[i * 3] = list[i]->uuid->uuid.repr;
        args[i * 3 + 1] = list[i]->name;
        args[i * 3 + 2] = list[i]->description;
    }
    args[serv->wrapper->team_n * 3] = NULL;
    return print_retcode(206, cretcodes(args), user->user_peer, true);
}

///
/// \brief List all the channel
///
/// \param user User info
/// \param serv Serv info
/// \param uuid Location uuid
/// \return true When operation succeed
/// \return false When operation failed
///
static bool command_list_chan(user_list_t *user, server_data_t *serv,
my_uuid_t *uuid)
{
    child_list_t list = get_team_child_list(serv->wrapper, uuid);

    char **args = NULL;
    channel_t *chan = NULL;

    if (list.size == 0)
        return print_retcode(310, NULL, user->user_peer, false);
    args = malloc(sizeof(char *) * (list.size * 3 + 1));
    if (args == NULL)
        return false;
    for (int i = 0; i < list.size; i++) {
        chan = wrapper_find_channel(serv->wrapper, list.list[i]);
        args[i * 3] = chan->uuid->uuid.repr;
        args[i * 3 + 1] = chan->name;
        args[i * 3 + 2] = chan->description;
    }
    args[list.size * 3] = NULL;
    return print_retcode(207, cretcodes(args), user->user_peer, true);
}

///
/// \brief List all the thread
///
/// \param user User info
/// \param serv Serv info
/// \param uuid Location uuid
/// \return true When operation succeed
/// \return false When operation failed
///
static bool command_list_thread(user_list_t *user, server_data_t *serv,
my_uuid_t *uuid)
{
    child_list_t list = get_channel_child_list(serv->wrapper, uuid);

    char **args = NULL;
    thread_t *thread = NULL;

    if (list.size == 0)
        return print_retcode(310, NULL, user->user_peer, false);
    args = malloc(sizeof(char *) * (list.size * 5 + 1));
    if (args == NULL)
        return false;
    for (int i = 0; i < list.size; i++) {
        thread = wrapper_find_thread(serv->wrapper, list.list[i]);
        args[i * 5] = thread->uuid->uuid.repr;
        args[i * 5 + 1] = thread->author->uuid.repr;
        args[i * 5 + 2] = thread_get_time(thread);
        args[i * 5 + 3] = thread->name;
        args[i * 5 + 4] = thread->body;
    }
    args[list.size * 5] = NULL;
    return print_retcode(208, cretcodes(args), user->user_peer, true);
}

///
/// \brief List all the comment
///
/// \param user User info
/// \param serv Serv info
/// \param uuid Location uuid
/// \return true When operation succeed
/// \return false When operation failed
///
static bool command_list_reply(user_list_t *user, server_data_t *serv,
my_uuid_t *uuid)
{
    child_list_t list = get_thread_child_list(serv->wrapper, uuid);

    char **args = NULL;
    comment_t *comment = NULL;

    if (list.size == 0)
        return print_retcode(310, NULL, user->user_peer, false);
    args = malloc(sizeof(char *) * (list.size * 4 + 1));
    if (args == NULL)
        return false;
    for (int i = 0; i < list.size; i++) {
        comment = wrapper_find_comment(serv->wrapper, list.list[i]);
        args[i * 4] = comment->thread->uuid.repr;
        args[i * 4 + 1] = comment->author->uuid.repr;
        args[i * 4 + 2] = comment_get_time(comment);
        args[i * 4 + 3] = comment->body;
    }
    args[list.size * 4] = NULL;
    return print_retcode(209, cretcodes(args), user->user_peer, true);
}

bool command_list(cli_command_t *cmd,
user_list_t *user, server_data_t *data)
{
    my_uuid_prefix_t type = my_uuid_get_prefix(&user->loc->uuid);

    (void) cmd;
    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (user->loc == NULL)
        return command_list_team(user, data);
    if (type == MY_UUID_PREFIX_TEAM)
        return command_list_chan(user, data, user->loc);
    if (type == MY_UUID_PREFIX_CHANNEL)
        return command_list_thread(user, data, user->loc);
    if (type == MY_UUID_PREFIX_THREAD)
        return command_list_reply(user, data, user->loc);
    return false;
}