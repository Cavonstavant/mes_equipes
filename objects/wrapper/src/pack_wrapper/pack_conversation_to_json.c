/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_conversation_to_json
*/

#include "pack_json.h"

static void conversation_to_json(conversation_t *conversation, FILE *file)
{
    fprintf(file, "{\"CON_UUID\":\"%s\",", conversation->uuid->uuid.repr);
    fprintf(file, "\"CON_Participants number\":%i,\"CON_Participants\":[", conversation->participant_n);
    for (int i = 0; i < conversation->participant_n; i++) {
        fprintf(file, "{\"CON_PAR_UUID\":\"%s\"}",
        conversation->participant[i]->uuid.repr);
        if (i + 1 < conversation->participant_n)
            fprintf(file, ",");
    }
    fprintf(file, "],\"CON_Messages number\":%i,\"CON_Messages\":[", conversation->message_n);
    for (int i = 0; i < conversation->message_n; i++) {
        fprintf(file, "{\"CON_MES_UUID\":\"%s\"},",
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
