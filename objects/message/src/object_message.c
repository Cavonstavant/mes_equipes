/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_message
*/

/// \file objects/message/src/object_message.c

#include "object_message.h"
#include <stdlib.h>

message_t *message_init(message_creation_t content)
{
    message_t *new_message = malloc(sizeof(message_t) * 1);

    if (new_message == MESSAGE_ERROR)
        return MESSAGE_ERROR;
    if ((new_message->uuid = my_uuid_init(DMS_)) == UUID_ERROR)
        return MESSAGE_ERROR;
    if ((new_message->body = body_init(content.body)) == BODY_ERROR)
        return MESSAGE_ERROR;
    new_message->time = time(NULL);
    return new_message;
}
