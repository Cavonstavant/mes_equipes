/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_wrapper
*/

/// \file objects/wrapper/include/object_wrapper.h

#ifndef OBJECT_WRAPPER_H_
    #define OBJECT_WRAPPER_H_

    #include "object_channel.h"
    #include "object_comment.h"
    #include "object_conversation.h"
    #include "object_description.h"
    #include "object_message.h"
    #include "object_team.h"
    #include "object_thread.h"
    #include "object_user.h"
    #include <stddef.h>

    ///
    /// \brief Error inside a Wrapper object
    ///
    #define WRAPPER_ERROR NULL

///
/// \brief Wrapper object, containing all Objects instance
///
typedef struct object_wrapper_s {
    /// List of all the channel
    channel_t **channels;
    /// Number of channels
    int channel_n;
    /// List of all the comment
    comment_t **comments;
    /// Number of comments
    int comment_n;
    /// List of all the conversation
    conversation_t **conversations;
    /// Number of conversations
    int conversation_n;
    /// List of all the message
    message_t **messages;
    /// Number of messages
    int message_n;
    /// List of all the team
    team_t **teams;
    /// Number of teams
    int team_n;
    /// List of all the thread
    thread_t **threads;
    /// Number of threads
    int thread_n;
    /// List of all the user
    user_t **users;
    /// Number of users
    int user_n;
} object_wrapper_t;

///
/// \brief Create a new wrapper object
/// Init all the object lists
///
/// \return object_wrapper_t* Newly created wrapper
///
object_wrapper_t *wrapper_init(void);

///
/// \brief Destroy a wrapper object
/// If the wrapper object is WRAPPER_ERROR, do nothing
///
/// \param wrapper Wrapper object to destroy
///
void wrapper_destroy(object_wrapper_t *wrapper);

///
/// \brief Dump all object in the wrapper
///
/// \param wrapper Wraper object to print
///
void wrapper_dump(object_wrapper_t *wrapper);

#endif /* !OBJECT_WRAPPER_H_ */
