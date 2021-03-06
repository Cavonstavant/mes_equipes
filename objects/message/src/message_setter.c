/*
** EPITECH PROJECT, 2022
** Project
** File description:
** message_setter
*/

/// \file objects/message/src/message_setter.c

#include "object_message.h"

char *strptime(const char *s, const char *format, struct tm *tm);

void message_edit_uuid(message_t *message, char *uuid)
{
    my_uuid_edit_content(message->uuid, uuid);
}

void message_edit_body(message_t *message, char *body)
{
    body_edit_content(message->body, body);
}

void message_edit_time(message_t *message, char *time)
{
    struct tm temp = {0};

    strptime(time, "%Y-%m-%d %H-%M-%S", &temp);
    message->time = mktime(&temp);
}
