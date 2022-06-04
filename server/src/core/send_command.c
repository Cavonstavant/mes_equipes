/*
** EPITECH PROJECT, 2022
** Project
** File description:
** send_command
*/

/// \file server/src/core/send_command.c

#include "cli_commands.h"
#include "rcodes.h"
#include "logging_server.h"

/// \brief Create a new conversation if the two user are not linked
/// \param user User info
/// \param send Uuid of second user
/// \param server Server info
/// \return true When operation succeed
/// \return false When operation failed
static bool command_create_conv(user_list_t *user, my_uuid_t *send,
server_data_t *server)
{
    if (find_conv_by_participant(server->wrapper, user->user_uuid, send))
        return true;
    if (!wrapper_new_conversation_to_user(server->wrapper,
    (conversation_creation_t) {
        user->user_uuid,
        send
    }, user->user_uuid, send)) {
        return print_retcode(503, NULL, user->user_peer, false);
    }
    return true;
}

bool command_send(cli_command_t *command,
user_list_t *user, server_data_t *server)
{
    my_uuid_t *send = my_uuid_fstring(command->arguments[0], server->wrapper);

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (!send || !wrapper_find_user(server->wrapper, send))
        return print_retcode(311, cretcodes((char *[]) {
        command->name, command->arguments[0], NULL}), user->user_peer, false);
    if (!command_create_conv(user, send, server))
        return false;
    if (!wrapper_new_message_to_conversation(server->wrapper,
    (message_creation_t) {
        command->arguments[1]
    }, find_conv_by_participant(server->wrapper, user->user_uuid, send)))
        return print_retcode(503, NULL, user->user_peer, false);
    server_event_private_message_sended(user->user_uuid->uuid.repr + 4,
    send->uuid.repr + 4, command->arguments[1]);
    send_user_event(server, send, 603, (char *[]) {
    user->user_uuid->uuid.repr + 4, wrapper_find_user(server->wrapper,
    user->user_uuid)->name, NULL});
    return true;
}

/// \brief Command list message
/// \param srv Server info
/// \param user User list
/// \param send Uuid of second user
/// \param conve Uuid of conversation
/// \return List of messages
static char **command_list_messages(server_data_t *srv, user_list_t *user,
my_uuid_t *send, my_uuid_t *conve)
{
    char **args = NULL;
    conversation_t *conv = wrapper_find_conversation(srv->wrapper, conve);

    if (!conv) {
        print_retcode(310, NULL, user->user_peer, false);
        return NULL;
    }
    args = malloc(sizeof(char *) * (conv->message_n * 3 + 1));
    if (args == NULL)
        return NULL;
    for (int i = 0; i < conv->message_n; i++) {
        args[i * 3] = send->uuid.repr;
        args[i * 3 + 1] = message_get_time(wrapper_find_message(srv->wrapper,
        conv->messages[i]));
        args[i * 3 + 2] = wrapper_find_message(srv->wrapper,
        conv->messages[i])->body;
    }
    args[conv->message_n * 3] = NULL;
    return args;
}

bool command_messages(cli_command_t *command,
user_list_t *user, server_data_t *server)
{
    my_uuid_t *send = my_uuid_fstring(command->arguments[0], server->wrapper);
    char **args = NULL;

    if (!user->is_auth)
        return print_retcode(401, NULL, user->user_peer, true);
    if (!send || !wrapper_find_user(server->wrapper, send))
        return print_retcode(311, cretcodes((char *[]) {
        command->name, command->arguments[0], NULL}), user->user_peer, false);
    args = command_list_messages(server, user, send,
    find_conv_by_participant(server->wrapper, user->user_uuid, send));
    if (args == NULL)
        return false;
    print_retcode(210, cretcodes(args), user->user_peer, true);
    free(args);
    return true;
}
