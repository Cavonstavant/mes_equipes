/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_channel_to_json
*/

/// \file objects/wrapper/src/pack_wrapper/pack_channel_to_json.c
/// \brief Pack a channel into a json file

#include "pack_json.h"

/// \brief Pack a channel into a json file
/// \param channel The channel to pack
/// \param file The file to write the channel into
static void channel_to_json(channel_t *channel, FILE *file)
{
    fprintf(file, "{\"CHA_UUID\":\"%s\",", channel->uuid->uuid.repr);
    fprintf(file, "\"CHA_Name\":\"%s\",", channel->name);
    fprintf(file, "\"CHA_Description\":\"%s\",", channel->description);
    fprintf(file, "\"CHA_Parent\":\"%s\",", channel->team->uuid.repr);
    fprintf(file, "\"CHA_Child number\":%i,\"CHA_Child\":[",
    channel->threads_n);
    for (int i = 0; i < channel->threads_n; i++) {
        fprintf(file, "{\"CHA_CHI_UUID\":\"%s\"}",
        channel->threads[i]->uuid.repr);
        if (i + 1 < channel->threads_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void pack_wrapper_to_json_channel(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "{\"Channel number\":%i,\"Channels\":[", wrapper->channel_n);
    for (int i = 0; i < wrapper->channel_n; i++) {
        channel_to_json(wrapper->channels[i], file);
        if (i + 1 < wrapper->channel_n)
            fprintf(file, ",");
    }
}
