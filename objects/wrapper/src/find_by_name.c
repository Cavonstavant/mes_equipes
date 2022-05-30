/*
** EPITECH PROJECT, 2022
** Project
** File description:
** find_by_name
*/

/// \file objects/wrapper/src/find_by_name.c

#include "object_wrapper.h"

my_uuid_t *find_channel_by_name(object_wrapper_t *wrapper, char *name)
{
    for (int i = 0; i < wrapper->channel_n; i++)
        if (strcmp(wrapper->channels[i]->name, name) == 0)
            return wrapper->channels[i]->uuid;
    return OBJECT_NOT_FOUND;
}

my_uuid_t *find_team_by_name(object_wrapper_t *wrapper, char *name)
{
    for (int i = 0; i < wrapper->team_n; i++)
        if (strcmp(wrapper->teams[i]->name, name) == 0)
            return wrapper->teams[i]->uuid;
    return OBJECT_NOT_FOUND;
}

my_uuid_t *find_thread_by_name(object_wrapper_t *wrapper, char *name)
{
    for (int i = 0; i < wrapper->thread_n; i++)
        if (strcmp(wrapper->threads[i]->name, name) == 0)
            return wrapper->threads[i]->uuid;
    return OBJECT_NOT_FOUND;
}

my_uuid_t *find_user_by_name(object_wrapper_t *wrapper, char *name)
{
    for (int i = 0; i < wrapper->user_n; i++)
        if (strcmp(wrapper->users[i]->name, name) == 0)
            return wrapper->users[i]->uuid;
    return OBJECT_NOT_FOUND;
}

my_uuid_t *find_conv_by_participant(object_wrapper_t *wrapper,
my_uuid_t *first, my_uuid_t *second)
{
    conversation_t *conv = NULL;

    for (int i = 0; i < wrapper->conversation_n; i++) {
        conv = wrapper->conversations[i];
        if (conversation_have_user(conv, first) &&
            conversation_have_user(conv, second))
            return conv->uuid;
    }
    return OBJECT_NOT_FOUND;
}