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

///
/// \brief Wrapper object, containing all Objects instance
///
typedef struct object_wrapper_s {
    /// List of all the body
    channel_t **bodys;
    /// List of all the comment
    comment_t **comments;
    /// List of all the conversation
    conversation_t **conversations;
    /// List of all the description
    description_t **descriptions;
    /// List of all the message
    message_t **messages;
    /// List of all the team
    team_t **teams;
    /// List of all the thread
    thread_t **threads;
    /// List of all the user
    user_t **users;
} object_wrapper_t;

#endif /* !OBJECT_WRAPPER_H_ */
