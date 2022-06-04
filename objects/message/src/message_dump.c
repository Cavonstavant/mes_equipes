/*
** EPITECH PROJECT, 2022
** Project
** File description:
** message_dump
*/

/// \file objects/message/src/message_dump.c

#include "object_message.h"
#include <stdio.h>
#include <stdlib.h>

char *message_get_time(message_t *message)
{
    char *time_display = malloc(sizeof(char) * 21);

    if (time_display == NULL)
        return NULL;
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&message->time));
    return time_display;
}

void message_dump(message_t *message)
{
    char time_display[20];

    printf("Message :\n");
    printf("\t");
    my_uuid_dump(message->uuid);
    printf("\t");
    body_dump(message->body);
    printf("\tTime : ");
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&message->time));
    printf("%s\n", time_display);
    fflush(NULL);
}
