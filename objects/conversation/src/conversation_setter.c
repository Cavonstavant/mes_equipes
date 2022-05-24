/*
** EPITECH PROJECT, 2022
** Project
** File description:
** conversation_setter
*/

/// \file objects/conversation/src/conversation_setter.c

#include "object_conversation.h"
#include <stdlib.h>

void conversation_edit_uuid(conversation_t *conversation, char *uuid)
{
    my_uuid_edit_content(conversation->uuid, uuid);
}

bool conversation_add_participant(conversation_t *conversation,
my_uuid_t *user)
{
    conversation->participant = realloc(conversation->participant,
    sizeof(my_uuid_t *) * (conversation->participant_n + 2));
    if (conversation->participant == NULL)
        return OPERATION_FAILED;
    conversation->participant[conversation->participant_n] = user;
    conversation->participant_n += 1;
    return OPERATION_SUCCESS;
}

bool conversation_add_message(conversation_t *conversation,
my_uuid_t *message)
{
    conversation->messages = realloc(conversation->messages,
    sizeof(my_uuid_t *) * (conversation->message_n + 2));
    if (conversation->messages == NULL)
        return OPERATION_FAILED;
    conversation->messages[conversation->message_n] = message;
    conversation->message_n += 1;
    return OPERATION_SUCCESS;
}