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
    if ((new_conv->participant = malloc(sizeof(my_uuid_t *) * 10))
        == UUID_ERROR)
        return CONVERSATION_ERROR;
    if ((new_conv->messages = malloc(sizeof(my_uuid_t *) * 250)) == UUID_ERROR)
        return CONVERSATION_ERROR;
    new_conv->messages[0] = NULL;
    new_conv->participant[0] = content.participant_one;
    new_conv->participant[1] = content.participant_two;
    return new_conv;
}