/*
** EPITECH PROJECT, 2022
** Project
** File description:
** lower_component_adding
*/

/// \file objects/wrapper/src/lower_component_adding.c

#include "lower_component_adding.h"

bool wrapper_adding_message(object_wrapper_t *wrapper,
message_creation_t content)
{
    message_t *new_message = message_init(content);

    if (new_message == USER_ERROR)
        return COMPONENT_ERROR;
    wrapper->messages = realloc(wrapper->messages,
    sizeof(message_t *) * (wrapper->message_n + 2));
    if (wrapper->messages == NULL)
        return COMPONENT_ERROR;
    wrapper->messages[wrapper->message_n] = new_message;
    wrapper->message_n += 1;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_comment(object_wrapper_t *wrapper,
comment_creation_t content)
{
    comment_t *new_comment = comment_init(content);

    if (new_comment == USER_ERROR)
        return COMPONENT_ERROR;
    wrapper->comments = realloc(wrapper->comments,
    sizeof(comment_t *) * (wrapper->comment_n + 2));
    if (wrapper->comments == NULL)
        return COMPONENT_ERROR;
    wrapper->comments[wrapper->comment_n] = new_comment;
    wrapper->comment_n += 1;
    return COMPONENT_SUCCESS;
}