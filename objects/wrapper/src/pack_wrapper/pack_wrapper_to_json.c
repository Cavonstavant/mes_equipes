/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** pack_wrapper_to_json
*/

/// \file objects/wrapper/src/pack_wrapper/pack_wrapper_to_json.c
/// \brief Pack a wrapper into a json file

#include <stdbool.h>
#include "pack_json.h"

bool pack_wrapper_to_json(object_wrapper_t *wrapper)
{
    FILE *file = fopen("server.json", "w+");

    if (!file || !wrapper)
        return false;
    pack_wrapper_to_json_channel(wrapper, file);
    pack_wrapper_to_json_comment(wrapper, file);
    pack_wrapper_to_json_conversation(wrapper, file);
    pack_wrapper_to_json_message(wrapper, file);
    pack_wrapper_to_json_team(wrapper, file);
    pack_wrapper_to_json_thread(wrapper, file);
    pack_wrapper_to_json_user(wrapper, file);
    fclose(file);
    return true;
}
