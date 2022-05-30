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
    #include <stdbool.h>

    ///
    /// \brief Error inside a conversation object
    ///
    #define CONVERSATION_ERROR NULL

    ///
    /// \brief Operation failed probably caused by a malloc
    ///
    #define OPERATION_FAILED false

    ///
    /// \brief Operation succeed
    ///
    #define OPERATION_SUCCESS true

///
/// \brief Comment object
///
typedef struct conversation_s {
    /// Uuid of the conversation
    my_uuid_t *uuid;
    /// Uuid of the attached thread
    my_uuid_t **participant;
    /// Number of participant
    int participant_n;
    /// Uuid of the attached user
    my_uuid_t **messages;
    /// Number of message
    int message_n;
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

///
/// \brief Dump a conversation object
///
/// \param conversation Conversation object to dump
///
void conversation_dump(conversation_t *conversation);

///
/// \brief Edit the content of a conversation object
///
/// \param conversation Conversation object to edit
/// \param uuid Uuid to change in the conversation object
///
void conversation_edit_uuid(conversation_t *conversation, char *uuid);

///
/// \brief Add a user in the participant list of a conversation object
///
/// \param conversation Conversation object
/// \param user Uuid object to add in the list
/// \return true When operation success
/// \return false When operation failed
///
bool conversation_add_participant(conversation_t *conversation,
my_uuid_t *user);

///
/// \brief Add a message in the messages list of a conversation object
///
/// \param conversation Conversation object
/// \param message Uuid object to add in the list
/// \return true When operation success
/// \return false When operation failed
///
bool conversation_add_message(conversation_t *conversation,
my_uuid_t *message);

#endif /* !OBJECT_CONVERSATION_H_ */
