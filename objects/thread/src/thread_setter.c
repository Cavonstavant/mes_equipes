/*
** EPITECH PROJECT, 2022
** Project
** File description:
** thread_setter
*/

/// \file objects/thread/src/thread_setter.c

#include "object_thread.h"
#include <stdlib.h>

char *strptime(const char *s, const char *format, struct tm *tm);

void thread_edit_name(thread_t *thread, char *name)
{
    name_edit_content(thread->name, name);
}

void thread_edit_body(thread_t *thread, char *body)
{
    body_edit_content(thread->body, body);
}

void thread_edit_time(thread_t *thread, char *time)
{
    struct tm temp = {0};

    strptime(time, "%Y-%m-%d %H:%M:%S", &temp);
    thread->date = mktime(&temp);
}

bool thread_add_comment(thread_t *thread, my_uuid_t *comment)
{
    thread->comments = realloc(thread->comments,
    sizeof(my_uuid_t *) * (thread->comment_n + 2));
    if (thread->comments == NULL)
        return OPERATION_FAILED;
    thread->comments[thread->comment_n] = comment;
    thread->comment_n += 1;
    return OPERATION_SUCCESS;
}
