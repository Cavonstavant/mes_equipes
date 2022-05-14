/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_comment
*/

/// \file objects/comment/src/object_comment.c

#include "object_comment.h"
#include <stdlib.h>

comment_t *comment_init(comment_creation_t content)
{
    comment_t *new_comment = malloc(sizeof(comment_t) * 1);

    if (new_comment == COMMENT_ERROR)
        return COMMENT_ERROR;
    if ((new_comment->uuid = my_uuid_init(COM_)) == UUID_ERROR)
        return COMMENT_ERROR;
    new_comment->thread = content.thread;
    new_comment->author = content.author;
    if ((new_comment->body = body_init(content.body)) == BODY_ERROR)
        return COMMENT_ERROR;
    new_comment->time = time(NULL);
    return new_comment;
}

void comment_destroy(comment_t *comment)
{
    if (comment == COMMENT_ERROR)
        return;
    my_uuid_destroy(comment->uuid);
    body_destroy(comment->body);
    free(comment);
}