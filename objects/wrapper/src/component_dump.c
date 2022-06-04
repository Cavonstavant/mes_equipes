/*
** EPITECH PROJECT, 2022
** Project
** File description:
** component_dump
*/

/// \file objects/wrapper/src/component_dump.c

#include "object_wrapper.h"

/// \brief Dump user of a wrapper object
/// \param wrapper Wrapper object to print
static void wrapper_dump_user(object_wrapper_t *wrapper)
{
    printf("--- %i Users ---\n", wrapper->user_n);
    for (int i = 0; i < wrapper->user_n; i++)
        user_dump(wrapper->users[i]);
}

void wrapper_dump(object_wrapper_t *wrapper)
{
    printf("--- %i Channels ---\n", wrapper->channel_n);
    for (int i = 0; i < wrapper->channel_n; i++)
        channel_dump(wrapper->channels[i]);
    printf("--- %i Comments ---\n", wrapper->comment_n);
    for (int i = 0; i < wrapper->comment_n; i++)
        comment_dump(wrapper->comments[i]);
    printf("--- %i Conversations ---\n", wrapper->conversation_n);
    for (int i = 0; i < wrapper->conversation_n; i++)
        conversation_dump(wrapper->conversations[i]);
    printf("--- %i Messages ---\n", wrapper->message_n);
    for (int i = 0; i < wrapper->message_n; i++)
        message_dump(wrapper->messages[i]);
    printf("--- %i Teams ---\n", wrapper->team_n);
    for (int i = 0; i < wrapper->team_n; i++)
        team_dump(wrapper->teams[i]);
    printf("--- %i Threads ---\n", wrapper->thread_n);
    for (int i = 0; i < wrapper->thread_n; i++)
        thread_dump(wrapper->threads[i]);
    wrapper_dump_user(wrapper);
}
