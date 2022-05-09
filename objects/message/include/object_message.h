/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_message
*/

/// \file objects/message/include/object_message.h

#ifndef OBJECT_MESSAGE_H_
    #define OBJECT_MESSAGE_H_

    #include "object_uuid.h"
    #include "object_body.h"
    #include <time.h>

///
/// \brief Message object
///
///
typedef struct message_s {
    /// Uuid of the message
    uuid_t uuid;
    /// Body of the message
    body_t body;
    /// Time of the message creation
    time_t time;
} message_t;

#endif /* !OBJECT_MESSAGE_H_ */
