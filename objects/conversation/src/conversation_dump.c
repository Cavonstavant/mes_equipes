/*
** EPITECH PROJECT, 2022
** Project
** File description:
** conversation_dump
*/

/// \file objects/conversation/src/conversation_dump.c

#include "object_conversation.h"
#include <stdio.h>

void conversation_dump(conversation_t *conversation)
{
    printf("Conversation :\n");
    printf("\t");
    my_uuid_dump(conversation->uuid);
    printf("\tParticipant :\n");
    for (int i = 0; i < conversation->participant_n; i++) {
        printf("\t\t");
        my_uuid_dump(conversation->participant[i]);
    }
    printf("\tMessage :\n");
    for (int i = 0; i < conversation->message_n; i++) {
        printf("\t\t");
        my_uuid_dump(conversation->messages[i]);
    }
    fflush(NULL);
}