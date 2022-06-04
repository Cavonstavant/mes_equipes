/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_message_to_json
*/

/// \file objects/wrapper/src/pack_wrapper/pack_message_to_json.c7
/// \brief Pack a message into a json file

#include "pack_json.h"

/// \brief Pack a message into a json file
/// \param message The message to pack
/// \param file The file to write the message into
static void message_to_json(message_t *message, FILE *file)
{
    char time_display[20];

    fprintf(file, "{\"MES_UUID\":\"%s\",", message->uuid->uuid.repr);
    fprintf(file, "\"MES_Body\":\"%s\",", message->body);
    strftime(time_display, 20, "%Y-%m-%d %H-%M-%S", localtime(&message->time));
    fprintf(file, "\"MES_Time\":\"%s\"}", time_display);
}

void pack_wrapper_to_json_message(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Message number\":%i,\"Messages\":[",
    wrapper->message_n);
    for (int i = 0; i < wrapper->message_n; i++) {
        message_to_json(wrapper->messages[i], file);
        if (i + 1 < wrapper->message_n)
            fprintf(file, ",");
    }
}
