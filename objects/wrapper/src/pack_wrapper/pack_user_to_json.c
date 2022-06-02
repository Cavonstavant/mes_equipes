/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_user_to_json
*/

/// \file objects/wrapper/src/pack_wrapper/pack_user_to_json.c
/// \brief Pack a user into a json file

#include "pack_json.h"

/// \brief Pack a user into a json file
/// \param user The user to pack
/// \param file The file to write the user into
static void user_to_json(user_t *user, FILE *file)
{
    fprintf(file, "{\"USR_UUID\":\"%s\",", user->uuid->uuid.repr);
    fprintf(file, "\"USR_Name\":\"%s\",", user->name);
    fprintf(file, "\"USR_Status\":\"%s\",",
    ((user->status == ONLINE) ? "online" : "offline"));
    fprintf(file, "\"USR_Team number\":%i,\"USR_Teams\":[", user->team_n);
    for (int i = 0; i < user->team_n; i++) {
        fprintf(file, "{\"USR_TEA_UUID\":\"%s\"}", user->teams[i]->uuid.repr);
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
