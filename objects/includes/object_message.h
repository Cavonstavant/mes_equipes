/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_message
*/

/// \file /objects/include/object_message.h

#ifndef OBJECT_MESSAGE_H_
    #define OBJECT_MESSAGE_H_

    #include "object_uuid.h"
    #include "object_body.h"
    #include <time.h>

///
///@brief Message object
///
///
typedef struct message_s {
    uuid_t uuid; /// Uuid of the message
    body_t body; /// Body of the message
    time_t time; /// Time of the message creation
} message_t;

#endif /* !OBJECT_MESSAGE_H_ */
