/*
** EPITECH PROJECT, 2022
** Project
** File description:
** comment_dump
*/

/// \file objects/comment/src/comment_dump.c

#include "object_comment.h"
#include <stdio.h>

void comment_dump(comment_t *comment)
{
    char time_display[20];

    printf("Comment :\n");
    printf("\t");
    my_uuid_dump(comment->uuid);
    printf("\t Parent : ");
    my_uuid_dump(comment->thread);
    printf("\t Author : ");
    my_uuid_dump(comment->author);
    printf("\t");
    body_dump(comment->body);
    printf("\t Time : ");
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&comment->time));
    print("%s\n", time_display);
    fflush(NULL);
}