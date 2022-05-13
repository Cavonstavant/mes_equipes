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
    /// \brief Error inside a message object
    ///
    #define MESSAGE_ERROR NULL

///
/// \brief Message object
///
///
typedef struct message_s {
    /// Uuid of the message
    my_uuid_t *uuid;
    /// Body of the message
    body_t body;
    /// Time of the message creation
    time_t time;
} message_t;

///
/// \brief Message creation object
/// Object containing all the information for a message creation
///
typedef struct message_creation_s {
    /// Initial body for the message creation
    char *body;
} message_creation_t;

///
/// \brief Init a new Message object
///
/// \param content Content of the new message object
/// \return message_t* Newly created message object
///
message_t *message_init(message_creation_t content);

///
/// \brief Destroy a message object
/// If the message is MESSAGE_ERROR, do nothing
///
/// \param message Message object to destroy
///
void message_destroy(message_t *message);

#endif /* !OBJECT_MESSAGE_H_ */
