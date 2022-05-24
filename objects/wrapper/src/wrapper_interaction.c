/*
** EPITECH PROJECT, 2022
** Project
** File description:
** wrapper_interaction
*/

/// \file objects/wrapper/src/wrappper_interaction.c

#include "object_wrapper.h"
#include "lower_component_adding.h"
#include "upper_component_adding.h"

bool wrapper_new_comment_to_thread(object_wrapper_t *wrapper,
comment_creation_t content, my_uuid_t *thread_uuid)
{
    thread_t *thread = NULL;

    if ((thread = wrapper_find_thread(wrapper, thread_uuid)) == NULL)
        return OPERATION_FAILED;
    content.thread = thread->uuid;
    if (!wrapper_adding_comment(wrapper, content))
        return OPERATION_FAILED;
    if (!thread_add_comment(thread,
    wrapper->comments[wrapper->comment_n - 1]->uuid))
        return OPERATION_FAILED;
    return OPERATION_SUCCEED;
}

bool wrapper_new_thread_to_channel(object_wrapper_t *wrapper,
thread_creation_t content, my_uuid_t *channel_uuid)
{
    channel_t *channel = NULL;

    if ((channel = wrapper_find_channel(wrapper, channel_uuid)) == NULL)
        return OPERATION_FAILED;
    content.channel = channel->uuid;
    if (!wrapper_adding_thread(wrapper, content))
        return OPERATION_FAILED;
    if (!channel_add_threads(channel,
    wrapper->threads[wrapper->thread_n - 1]->uuid))
        return OPERATION_FAILED;
    return OPERATION_SUCCEED;
}