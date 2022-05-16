/*
** EPITECH PROJECT, 2022
** Project
** File description:
** message_dump
*/

/// \file objects/message/src/message_dump.c

#include "object_message.h"
#include <stdio.h>

void message_dump(message_t *message)
{
    char time_display[20];

    printf("Comment :\n");
    printf("\t");
    my_uuid_dump(message->uuid);
    printf("\t");
    body_dump(message->body);
    printf("\tTime : ");
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&message->time));
    printf("%s\n", time_display);
    fflush(NULL);
}