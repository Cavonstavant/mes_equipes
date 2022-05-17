/*
** EPITECH PROJECT, 2022
** Project
** File description:
** comment_setter
*/

/// \file objects/comment/src/comment_setter.c

#include "object_comment.h"

void comment_edit_uuid(comment_t *comment, char *uuid)
{
    my_uuid_edit_content(comment->uuid, uuid);
}

void comment_edit_parent(comment_t *comment, char *parent)
{
    my_uuid_edit_content(comment->thread, parent);
}

void comment_edit_author(comment_t *comment, char *author)
{
    my_uuid_edit_content(comment->author, author);
}

void comment_edit_body(comment_t *comment, char *body)
{
    body_edit_content(comment->body, body);
}

void comment_edit_time(comment_t *comment, char *time)
{
    struct tm temp = {0};

    strftime(time, strlen(time), "%Y-%b-%d %H:%M:%S", &temp);
    comment->time = mktime(&temp);
}