/*
** EPITECH PROJECT, 2022
** Project
** File description:
** wrapper_adding
*/

/// \file objects/wrapper/src/upper_component_adding.c

#include "upper_component_adding.h"

bool wrapper_adding_user(object_wrapper_t *wrapper, user_creation_t content)
{
    (void) wrapper;
    (void) content;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_team(object_wrapper_t *wrapper, team_creation_t content)
{
    (void) wrapper;
    (void) content;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_conversation(object_wrapper_t *wrapper,
conversation_creation_t content)
{
    (void) wrapper;
    (void) content;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_thread(object_wrapper_t *wrapper,
thread_creation_t content)
{
    (void) wrapper;
    (void) content;
    return COMPONENT_SUCCESS;
}

bool wrapper_adding_channel(object_wrapper_t *wrapper,
channel_creation_t content)
{
    (void) content;
    (void) wrapper;
    return COMPONENT_SUCCESS;
}