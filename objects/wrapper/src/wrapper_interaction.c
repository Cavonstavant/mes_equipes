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

bool wrapper_new_channel_to_team(object_wrapper_t *wrapper,
channel_creation_t content, my_uuid_t *team_uuid)
{
    team_t *team = NULL;

    if ((team = wrapper_find_team(wrapper, team_uuid)) == NULL)
        return OPERATION_FAILED;
    content.team = team->uuid;
    if (!wrapper_adding_channel(wrapper, content))
        return OPERATION_FAILED;
    if (!team_add_channel(team,
    wrapper->channels[wrapper->channel_n - 1]->uuid))
        return OPERATION_FAILED;
    return OPERATION_SUCCEED;
}

bool wrapper_new_conversation_to_user(object_wrapper_t *wrapper,
conversation_creation_t content, my_uuid_t *first_uuid, my_uuid_t *second_uuid)
{
    user_t *first_user = NULL;
    user_t *second_user = NULL;

    if ((first_user = wrapper_find_user(wrapper, first_uuid)) == NULL)
        return OPERATION_FAILED;
    if ((second_user = wrapper_find_user(wrapper, second_uuid)) == NULL)
    content.participant_one = first_user->uuid;
    content.participant_two = second_user->uuid;
    if (!wrapper_adding_conversation(wrapper, content))
        return OPERATION_FAILED;
    if (!user_add_conversation(first_user, 
    wrapper->conversations[wrapper->conversation_n - 1]->uuid))
        return OPERATION_FAILED;
    if (!user_add_conversation(second_user, 
    wrapper->conversations[wrapper->conversation_n - 1]->uuid))
        return OPERATION_FAILED;
    return OPERATION_SUCCEED;
}

bool wrapper_new_message_to_conversation(object_wrapper_t *wrapper,
message_creation_t content, my_uuid_t *conv_uuid)
{
    conversation_t *conv = NULL;

    if ((conv = wrapper_find_conversation(wrapper, conv_uuid)) == NULL)
        return OPERATION_FAILED;
    if (!wrapper_adding_message(wrapper, content))
        return OPERATION_FAILED;
    if (!conversation_add_message(conv,
    wrapper->messages[wrapper->message_n - 1]->uuid))
        return OPERATION_FAILED;
    return OPERATION_SUCCEED;
}