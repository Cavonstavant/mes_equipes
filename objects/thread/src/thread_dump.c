/*
** EPITECH PROJECT, 2022
** Project
** File description:
** thread_dump
*/

/// \file objects/thread/src/thread_dump.c

#include "object_thread.h"
#include <stdio.h>

///
/// \brief Dump the thread time
///
/// \param thread Thread object to print
///
static void thread_dump_time(thread_t *thread)
{
    char time_display[20];

    printf("\tTime : ");
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&thread->date));
    printf("%s\n", time_display);
}

void thread_dump(thread_t *thread)
{
    printf("Thread :\n");
    printf("\t");
    my_uuid_dump(thread->uuid);
    printf("\tParent : ");
    my_uuid_dump(thread->channel);
    printf("\tAuthor : ");
    my_uuid_dump(thread->author);
    printf("\t");
    name_dump(thread->name);
    printf("\t");
    body_dump(thread->body);
    thread_dump_time(thread);
    printf("\tComments :\n");
    for (int i = 0; i < thread->comment_n; i++) {
        printf("\t\t");
        my_uuid_dump(thread->comments[i]);
    }
    fflush(NULL);
}