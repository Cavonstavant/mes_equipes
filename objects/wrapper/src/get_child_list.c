/*
** EPITECH PROJECT, 2022
** Project
** File description:
** get_child_list
*/

/// \file objects/wrapper/src/get_child_list.c

#include "object_wrapper.h"

child_list_t get_channel_child_list(object_wrapper_t *wrapper,
my_uuid_t *channel_uuid)
{
    channel_t *channel = wrapper_find_channel(wrapper, channel_uuid);
    child_list_t res;

    if (channel == OBJECT_NOT_FOUND)
        return (child_list_t) {
            OBJECT_NOT_FOUND,
            -1
        };
    res.list = channel->threads;
    res.size = channel->threads_n;
    return res;
}

child_list_t get_conversation_child_list(object_wrapper_t *wrapper,
my_uuid_t *conversation_uuid)
{
    conversation_t *conversation = wrapper_find_conversation(wrapper,
    conversation_uuid);
    child_list_t res;

    if (conversation == OBJECT_NOT_FOUND)
        return (child_list_t) {
            OBJECT_NOT_FOUND,
            -1
        };
    res.list = conversation->messages;
    res.size = conversation->message_n;
    return res;
}

child_list_t get_team_child_list(object_wrapper_t *wrapper,
my_uuid_t *team_uuid)
{
    team_t *team = wrapper_find_team(wrapper, team_uuid);
    child_list_t res;

    if (team == OBJECT_NOT_FOUND)
        return (child_list_t) {
            OBJECT_NOT_FOUND,
            -1
        };
    res.list = team->channels;
    res.size = team->channel_n;
    return res;
}

child_list_t get_thread_child_list(object_wrapper_t *wrapper,
my_uuid_t *thread_uuid)
{
    thread_t *thread = wrapper_find_thread(wrapper, thread_uuid);
    child_list_t res;

    if (thread == OBJECT_NOT_FOUND)
        return (child_list_t) {
            OBJECT_NOT_FOUND,
            -1
        };
    res.list = thread->comments;
    res.size = thread->comment_n;
    return res;
}