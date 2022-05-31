/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_user_to_json
*/

#include "packer_json.h"

static void user_to_json(user_t *user, FILE *file)
{
    fprintf(file, "{\"UUID\":\"%s\",", user->uuid->uuid.repr);
    fprintf(file, "\"Name\":\"%s\",", user->name);
    fprintf(file, "\"Status\":\"%s\",",
    ((user->status == ONLINE) ? "online" : "offline"));
    fprintf(file, "\"Teams\":[");
    for (int i = 0; i < user->team_n; i++) {
        fprintf(file, "{\"UUID\":\"%s\"}", user->teams[i]->uuid.repr);
        if (i + 1 < user->team_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}

void pack_wrapper_to_json_user(object_wrapper_t *wrapper, FILE *file)
{
    fprintf(file, "],\"User number\":%i,\"Users\":[", wrapper->user_n);
    for (int i = 0; i < wrapper->user_n; i++) {
        user_to_json(wrapper->users[i], file);
        if (i + 1 < wrapper->user_n)
            fprintf(file, ",");
    }
    fprintf(file, "]}");
}
