/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_channel_to_json
*/

#include "packer_json.h"

static void channel_to_json(channel_t *channel, FILE *file)
{
    fprintf(file, "{\"UUID\":\"%s\",", channel->uuid->uuid.repr);
    fprintf(file, "\"Name\":\"%s\",", channel->name);
    fprintf(file, "\"Description\":\"%s\",", channel->description);
    fprintf(file, "\"Parent\":\"%s\",", channel->team->uuid.repr);
    fprintf(file, "\"Child\":[");
    for (int i = 0; i < channel->threads_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"},", channel->threads[i]->uuid.repr);
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
