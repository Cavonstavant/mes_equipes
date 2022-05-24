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