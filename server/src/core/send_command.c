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

///
/// \brief Create a new conversation if the two user are not linked
///
/// \param user User info
/// \param send Uuid of second user
/// \param server Server info
/// \return true When operation succeed
/// \return false When operation failed
///
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
    if (!command_create_conv(user, send, server))
        return false;
    if (!wrapper_new_message_to_conversation(server->wrapper,
    (message_creation_t) {
        command->arguments[1]
    }, find_conv_by_participant(server->wrapper, user->user_uuid, send)))
        return print_retcode(503, NULL, user->user_peer, false);
    server_event_private_message_sended(user->user_uuid->uuid.repr + 4,
    send->uuid.repr + 4, command->arguments[1]);
    return print_retcode(200, NULL, user->user_peer, true);
}