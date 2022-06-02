/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_team
*/

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

static bool fill_channels(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int channel_nbr = get_balise_number(file + index, channel_nb, "\"TEA_Channel number\":");
    char *channels = NULL;
    int nbr = 0;

    if (channel_nbr < 0)
        return false;
    for (int i = 0; i <= channel_nb; i++) {
        nbr = find_str(file + index, "\"TEA_Channels\":");
        if (nbr < 0)
            return false;
        index += nbr;
    }
    for (int i = 0; i < channel_nbr; i++) {
        channels = get_balise_content(file + index, i, "\"TEA_CHA_UUID\":");
        if (!channels)
            return false;
        team_add_channel(wrapper->teams[channel_nb], my_uuid_from_string(channels));
        free(channels);
    }
    return true;
}

static bool fill_users(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int user_nbr = get_balise_number(file + index, channel_nb, "\"TEA_User number\":");
    char *users = NULL;
    int nbr = 0;

    if (user_nbr < 0)
        return false;
    for (int i = 0; i <= channel_nb; i++) {
        nbr = find_str(file + index, "\"TEA_Users\":");
        if (nbr < 0)
            return false;
        index += nbr;
    }
    for (int i = 0; i < user_nbr; i++) {
        users = get_balise_content(file + index, i, "\"TEA_USR_UUID\":");
        if (!users)
            return false;
        team_add_user(wrapper->teams[channel_nb], my_uuid_from_string(users));
        free(users);
    }
    return true;
}

static bool create_new_team(object_wrapper_t *wrapper, char *file, int channel_nb)
{
    int index = find_str(file, "\"Teams\":");
    char *name = get_balise_content(file + index, channel_nb, "\"TEA_Name\":");
    char *uuid = get_balise_content(file + index, channel_nb, "\"TEA_UUID\":");
    char *desc = get_balise_content(file + index, channel_nb, "\"TEA_Description\":");

    if (!name || !uuid || !desc)
        return false;
    if (!wrapper_adding_team(wrapper, (team_creation_t) {name, desc}))
        return false;
    team_edit_uuid(wrapper->teams[channel_nb], uuid);
    if (!fill_channels(wrapper, file, index, channel_nb))
        return false;
    if (!fill_users(wrapper, file, index, channel_nb))
        return false;
    free(name);
    free(uuid);
    free(desc);
    return true;
}

bool unpack_json_to_wrapper_team(object_wrapper_t *wrapper, char *file)
{
    int channel_nbr = get_balise_number(file, 0, "\"Team number\":");

    if (channel_nbr < 0)
        return false;
    for (int i = 0; i < channel_nbr; i++) {
        if (!create_new_team(wrapper, file, i))
            return false;
    }
    return true;
}
