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

///
/// \brief Destroy all the content of a wrapper object
///
/// \param wrapper Wrapper object to destroy
///
static void wrapper_destroy_content(object_wrapper_t *wrapper)
{
    for (int i = 0; i < wrapper->team_n; i++)
        team_destroy(wrapper->teams[i]);
    free(wrapper->teams);
    for (int i = 0; i < wrapper->thread_n; i++)
        thread_destroy(wrapper->threads[i]);
    free(wrapper->threads);
    for (int i = 0; i < wrapper->user_n; i++)
        user_destroy(wrapper->users[i]);
    free(wrapper->users);
}

void wrapper_destroy(object_wrapper_t *wrapper)
{
    if (wrapper == WRAPPER_ERROR)
        return;
    for (int i = 0; i < wrapper->channel_n; i++)
        channel_destroy(wrapper->channels[i]);
    free(wrapper->channels);
    for (int i = 0; i < wrapper->comment_n; i++)
        comment_destroy(wrapper->comments[i]);
    free(wrapper->comments);
    for (int i = 0; i < wrapper->conversation_n; i++)
        conversation_destroy(wrapper->conversations[i]);
    free(wrapper->conversations);
    for (int i = 0; i < wrapper->message_n; i++)
        message_destroy(wrapper->messages[i]);
    free(wrapper->messages);
    wrapper_destroy_content(wrapper);
    free(wrapper);
}