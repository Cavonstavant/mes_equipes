/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_conversation
*/

/// \file /objects/include/object_conversation.h

#ifndef OBJECT_CONVERSATION_H_
    #define OBJECT_CONVERSATION_H_

    #include "object_uuid.h"

///
/// \brief Conversation object
///
///
typedef struct conversation_s {
    /// Uuid of the channel
    uuid_t uuid;
    /// Uuid list of the attached user
    uuid_t *users;
    /// Uuid list of the attached message
    uuid_t *message;
} conversation_t;

#endif /* !OBJECT_CONVERSATION_H_ */
