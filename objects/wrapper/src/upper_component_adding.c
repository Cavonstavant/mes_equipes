/*
** EPITECH PROJECT, 2022
** Project
** File description:
** upper_component_adding
*/

/// \file objects/wrapper/src/upper_component_adding.c

#include "upper_component_adding.h"

bool wrapper_adding_user(object_wrapper_t *wrapper, user_creation_t content)
{
    user_t *new_user = user_init(content);

    if (new_user == USER_ERROR)
        return COMPONENT_ERROR;
    wrapper->users = realloc(wrapper->users,
    sizeof(user_t *) * (wrapper->user_n + 2));
    if (wrapper->users == NULL)
        return COMPONENT_ERROR;
    wrapper->users[wrapper->user_n] = new_user;
    wrapper->user_n += 1;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_team(object_wrapper_t *wrapper, team_creation_t content)
{
    team_t *new_team = team_init(content);

    if (new_team == USER_ERROR)
        return COMPONENT_ERROR;
    wrapper->teams = realloc(wrapper->teams,
    sizeof(team_t *) * (wrapper->team_n + 2));
    if (wrapper->teams == NULL)
        return COMPONENT_ERROR;
    wrapper->teams[wrapper->team_n] = new_team;
    wrapper->team_n += 1;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_conversation(object_wrapper_t *wrapper,
conversation_creation_t content)
{
    conversation_t *new_conversation = conversation_init(content);

    if (new_conversation == USER_ERROR)
        return COMPONENT_ERROR;
    wrapper->conversations = realloc(wrapper->conversations,
    sizeof(conversation_t *) * (wrapper->conversation_n + 2));
    if (wrapper->conversations == NULL)
        return COMPONENT_ERROR;
    wrapper->conversations[wrapper->conversation_n] = new_conversation;
    wrapper->conversation_n += 1;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_thread(object_wrapper_t *wrapper,
thread_creation_t content)
{
    thread_t *new_thread = thread_init(content);

    if (new_thread == USER_ERROR)
        return COMPONENT_ERROR;
    wrapper->threads = realloc(wrapper->threads,
    sizeof(thread_t *) * (wrapper->thread_n + 2));
    if (wrapper->threads == NULL)
        return COMPONENT_ERROR;
    wrapper->threads[wrapper->thread_n] = new_thread;
    wrapper->thread_n += 1;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_channel(object_wrapper_t *wrapper,
channel_creation_t content)
{
    channel_t *new_channel = channel_init(content);

    if (new_channel == USER_ERROR)
        return COMPONENT_ERROR;
    wrapper->channels = realloc(wrapper->channels,
    sizeof(channel_t *) * (wrapper->channel_n + 2));
    if (wrapper->channels == NULL)
        return COMPONENT_ERROR;
    wrapper->channels[wrapper->channel_n] = new_channel;
    wrapper->channel_n += 1;
    return COMPONENT_SUCCESS;
}