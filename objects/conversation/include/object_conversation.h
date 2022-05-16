/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_conversation
*/

/// \file objects/conversation/include/object_conversation.h

#ifndef OBJECT_CONVERSATION_H_
    #define OBJECT_CONVERSATION_H_

    #include "object_uuid.h"
    #include "object_body.h"
    #include <time.h>

    ///
    /// \brief Error inside a conversation object
    ///
    #define CONVERSATION_ERROR NULL

///
/// \brief Comment object
///
///
typedef struct conversation_s {
    /// Uuid of the conversation
    my_uuid_t *uuid;
    /// Uuid of the attached thread
    my_uuid_t **participant;
    /// Number of participant
    int n_participant;
    /// Uuid of the attached user
    my_uuid_t **messages;
    /// Number of message
    int n_message;
} conversation_t;

///
/// \brief Comment creation object
/// Object containing all the information for a conversation creation
///
typedef struct conversation_creation_s {
    /// Uuid of the first user
    my_uuid_t *participant_one;
    /// Uuid of the second user
    my_uuid_t *participant_two;
} conversation_creation_t;

///
/// \brief Init a new Conversation object
///
/// \param content Content of the new conversation object
/// \return conversation_t* Newly created conversation object
///
conversation_t *conversation_init(conversation_creation_t content);

///
/// \brief Destroy a conversation object
/// If the conversation is CONVERSATION_ERROR, do nothing
///
/// \param conversation Conversation object to destroy
///
void conversation_destroy(conversation_t *conversation);

#endif /* !OBJECT_CONVERSATION_H_ */
