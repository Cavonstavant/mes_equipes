/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_conversation_to_json
*/

#include "packer_json.h"

static void conversation_to_json(conversation_t *conversation, FILE *file)
{
    fprintf(file, "{\"UUID\":\"%s\",", conversation->uuid->uuid.repr);
    fprintf(file, "\"Participants\":[");
    for (int i = 0; i < conversation->participant_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}",
        conversation->participant[i]->uuid.repr);
        if (i + 1 < conversation->participant_n)
            fprintf(file, ",");
    }
    fprintf(file, "],\"Messages\":[");
    for (int i = 0; i < conversation->message_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"},",
        conversation->messages[i]->uuid.repr);
        if (i + 1 < conversation->message_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void pack_wrapper_to_json_conversation(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Conversation number\":%i,\"Conversation\":[",
    wrapper->conversation_n);
    for (int i = 0; i < wrapper->conversation_n; i++) {
        conversation_to_json(wrapper->conversations[i], file);
        if (i + 1 < wrapper->conversation_n)
            fprintf(file, ",");
    }
}
