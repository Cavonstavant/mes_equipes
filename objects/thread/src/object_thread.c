/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_threads
*/

/// \file objects/thread/src/object_thread.c

#include "object_thread.h"
#include <stdlib.h>

thread_t *thread_init(thread_creation_t content)
{
    thread_t *new_thread = malloc(sizeof(thread_t) * 1);

    if (new_thread == THREAD_ERROR)
        return THREAD_ERROR;
    if ((new_thread->uuid = my_uuid_init(THR_)) == UUID_ERROR)
        return THREAD_ERROR;
    if ((new_thread->name = name_init(content.name)) == NAME_ERROR)
        return THREAD_ERROR;
    if ((new_thread->body = body_init(content.body)) == BODY_ERROR)
        return THREAD_ERROR;
    if ((new_thread->comments = malloc(sizeof(my_uuid_t *) * 20))
        == UUID_ERROR)
        return THREAD_ERROR;
    new_thread->author = content.author;
    new_thread->channel = content.channel;
    new_thread->date = time(NULL);
    new_thread->comments[0] = NULL;
    return new_thread;
}

void thread_destroy(thread_t *thread)
{
    if (thread == THREAD_ERROR)
        return;
    name_destroy(thread->name);
    body_destroy(thread->body);
    my_uuid_destroy(thread->uuid);
    free(thread->comments);
    free(thread);
}