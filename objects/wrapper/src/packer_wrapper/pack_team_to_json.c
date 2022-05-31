/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_team_to_json
*/

#include "packer_json.h"

static void team_to_json(team_t *team, FILE *file)
{
    fprintf(file, "{\"UUID\":\"%s\",", team->uuid->uuid.repr);
    fprintf(file, "\"Name\":\"%s\",", team->name);
    fprintf(file, "\"Description\":\"%s\",", team->description);
    fprintf(file, "\"Channels\":[");
    for (int i = 0; i < team->channel_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}", team->channels[i]->uuid.repr);
        if (i + 1 < team->channel_n)
            fprintf(file, ",");
    }
    fprintf(file, "],\"Users\":[");
    for (int i = 0; i < team->user_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}", team->users[i]->uuid.repr);
        if (i + 1 < team->user_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void pack_wrapper_to_json_team(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"Team number\":%i,\"Teams\":[", wrapper->team_n);
    for (int i = 0; i < wrapper->team_n; i++) {
        team_to_json(wrapper->teams[i], file);
        if (i + 1 < wrapper->team_n)
            fprintf(file, ",");
    }
}
