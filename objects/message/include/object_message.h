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

    /// \brief Error inside a message object
    #define MESSAGE_ERROR NULL

/// \brief Message object
typedef struct message_s {
    /// Uuid of the message
    my_uuid_t *uuid;
    /// Body of the message
    body_t body;
    /// Time of the message creation
    time_t time;
} message_t;

/// \brief Message creation object
/// Object containing all the information for a message creation
typedef struct message_creation_s {
    /// Initial body for the message creation
    char *body;
} message_creation_t;

/// \brief Init a new Message object
/// \param content Content of the new message object
/// \return message_t* Newly created message object
message_t *message_init(message_creation_t content);

/// \brief Destroy a message object
/// If the message is MESSAGE_ERROR, do nothing
/// \param message Message object to destroy
void message_destroy(message_t *message);

/// \brief Dump a message object
/// \param message Message object to print
void message_dump(message_t *message);

/// \brief Edit the uuid of a message object
/// \param message Message object to edit
/// \param uuid Uuid to change in the message object
void message_edit_uuid(message_t *message, char *uuid);

/// \brief Edit the body of a message object
/// \param message Message object to edit
/// \param body Body to change in the message object
void message_edit_body(message_t *message, char *body);

/// \brief Edit the time of a message object
/// \param message Message object to edit
/// \param time Time to change in the message object
void message_edit_time(message_t *message, char *time);

/// \brief Get the time creation of the message in string format
/// \param message Message object
/// \return char* Time in string
char *message_get_time(message_t *message);

#endif /* !OBJECT_MESSAGE_H_ */
