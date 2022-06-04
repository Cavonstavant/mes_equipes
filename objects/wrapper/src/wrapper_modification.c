/*
** EPITECH PROJECT, 2022
** Project
** File description:
** wrapper_modification
*/

/// \file objects/wraper/src/wrapper_modification.c

#include "object_wrapper.h"
#include "lower_component_adding.h"
#include "upper_component_adding.h"

bool wrapper_user_join_conversation(object_wrapper_t *wrapper,
my_uuid_t *user_uuid, my_uuid_t *conversation_uuid)
{
    user_t *user = NULL;
    conversation_t *conv = NULL;

    if ((user = wrapper_find_user(wrapper, user_uuid)) == NULL)
        return OPERATION_FAILED;
    if ((conv = wrapper_find_conversation(wrapper, conversation_uuid)) == NULL)
        return OPERATION_FAILED;
    if (!conversation_add_participant(conv, user->uuid))
        return OPERATION_FAILED;
    if (!user_add_conversation(user, conv->uuid))
        return OPERATION_FAILED;
    return OPERATION_SUCCEED;
}

bool wrapper_user_join_team(object_wrapper_t *wrapper,
my_uuid_t *user_uuid, my_uuid_t *team_uuid)
{
    user_t *user = NULL;
    team_t *team = NULL;

    if ((user = wrapper_find_user(wrapper, user_uuid)) == NULL)
        return OPERATION_FAILED;
    if ((team = wrapper_find_team(wrapper, team_uuid)) == NULL)
        return OPERATION_FAILED;
    if (!user_add_team(user, team->uuid))
        return OPERATION_FAILED;
    if (!team_add_user(team, user->uuid))
        return OPERATION_FAILED;
    return OPERATION_SUCCEED;
}

bool wrapper_user_leave_team(object_wrapper_t *wrapper,
my_uuid_t *user_uuid, my_uuid_t *team_uuid)
{
    user_t *user = NULL;
    team_t *team = NULL;

    if ((user = wrapper_find_user(wrapper, user_uuid)) == NULL)
        return OPERATION_FAILED;
    if ((team = wrapper_find_team(wrapper, team_uuid)) == NULL)
        return OPERATION_FAILED;
    if (!user_remove_team(user, team->uuid))
        return OPERATION_FAILED;
    if (!team_remove_user(team, user->uuid))
        return OPERATION_FAILED;
    return OPERATION_SUCCEED;
}

bool wrapper_find_channel_tm(object_wrapper_t *wrapper, my_uuid_t *chan,
my_uuid_t *team)
{
    if (!wrapper_find_channel(wrapper, chan))
        return false;
    if (!my_uuid_cmp(get_associated_team_channel(wrapper, chan), team))
        return false;
    return true;
}

bool wrapper_find_thread_tm(object_wrapper_t *wrapper, my_uuid_t *thread,
my_uuid_t *chan)
{
    if (!wrapper_find_thread(wrapper, thread))
        return false;
    if (!get_associated_team_thread(wrapper, thread))
        return false;
    if (!get_associated_team_channel(wrapper, chan))
        return false;
    if (!my_uuid_cmp(get_associated_team_thread(wrapper, thread),
        get_associated_team_channel(wrapper, chan)))
        return false;
    return true;
}
