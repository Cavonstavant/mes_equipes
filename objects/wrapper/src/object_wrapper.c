/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_wrapper
*/

/// \file objects/wrapper/src/object_wrapper.c

#include "object_wrapper.h"
#include <stdlib.h>

///
/// \brief Init all the object lists
///
/// \param wrapper Current wrapper object
/// \return object_wrapper_t* Newly filled wrapper object
///
static object_wrapper_t *wrapper_init_content(object_wrapper_t *wrapper)
{
    if ((wrapper->conversations = malloc(sizeof(conversation_t *)))
        == CONVERSATION_ERROR)
        return WRAPPER_ERROR;
    wrapper->conversation_n = 0;
    if ((wrapper->descriptions = malloc(sizeof(description_t *)))
        == DESCRIPTION_ERROR)
        return WRAPPER_ERROR;
    wrapper->description_n = 0;
    if ((wrapper->conversations = malloc(sizeof(conversation_t *)))
        == CONVERSATION_ERROR)
        return WRAPPER_ERROR;
    wrapper->conversation_n = 0;
    if ((wrapper->messages = malloc(sizeof(message_t *))) == MESSAGE_ERROR)
        return WRAPPER_ERROR;
    wrapper->message_n = 0;
    if ((wrapper->teams = malloc(sizeof(team_t *))) == TEAM_ERROR)
        return WRAPPER_ERROR;
    wrapper->team_n = 0;
    return wrapper;
}

object_wrapper_t *wrapper_init(void)
{
    object_wrapper_t *wrapper = malloc(sizeof(object_wrapper_t) * 1);

    if (wrapper == NULL)
        return WRAPPER_ERROR;
    if ((wrapper->channels = malloc(sizeof(channel_t *))) == CHANNEL_ERROR)
        return WRAPPER_ERROR;
    wrapper->channel_n = 0;
    if ((wrapper->comments = malloc(sizeof(comment_t *))) == COMMENT_ERROR)
        return WRAPPER_ERROR;
    wrapper->comment_n = 0;
    if ((wrapper->users = malloc(sizeof(user_t *))) == USER_ERROR)
        return WRAPPER_ERROR;
    wrapper->user_n = 0;
    if ((wrapper->threads = malloc(sizeof(thread_t *))) == THREAD_ERROR)
        return WRAPPER_ERROR;
    wrapper->thread_n = 0;
    if (wrapper_init_content(wrapper) == WRAPPER_ERROR)
        return WRAPPER_ERROR;
    return wrapper;
}