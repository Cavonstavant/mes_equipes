/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_conversation
*/

/// \file objects/conversation/src/object_conversation.c

#include "object_conversation.h"
#include <stdlib.h>

conversation_t *conversation_init(conversation_creation_t content)
{
    conversation_t *new_conv = malloc(sizeof(conversation_t) * 1);

    if (new_conv == CONVERSATION_ERROR)
        return CONVERSATION_ERROR;
    if ((new_conv->uuid = my_uuid_init(CON_)) == UUID_ERROR)
        return CONVERSATION_ERROR;
    if ((new_conv->participant = malloc(sizeof(my_uuid_t *) * 2))
        == UUID_ERROR)
        return CONVERSATION_ERROR;
    if ((new_conv->messages = malloc(sizeof(my_uuid_t *))) == UUID_ERROR)
        return CONVERSATION_ERROR;
    new_conv->message_n = 0;
    new_conv->participant[0] = content.participant_one;
    new_conv->participant[1] = content.participant_two;
    new_conv->participant_n = 2;
    return new_conv;
}

void conversation_destroy(conversation_t *conversation)
{
    if (conversation == CONVERSATION_ERROR)
        return;
    my_uuid_destroy(conversation->uuid);
    free(conversation->participant);
    free(conversation->messages);
    free(conversation);
}