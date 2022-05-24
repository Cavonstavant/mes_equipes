/*
** EPITECH PROJECT, 2022
** Project
** File description:
** wrapper_interaction
*/

/// \file objects/wrapper/src/wrappper_interaction.c

#include "object_wrapper.h"
#include  "lower_component_adding.h"

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