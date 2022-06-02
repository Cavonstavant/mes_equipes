/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_user
*/

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

static bool fill_teams(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int team_nbr = get_balise_number(file + index, channel_nb, "\"USR_Team number\":");
    char *team = NULL;
    int nbr = 0;

    if (team_nbr < 0)
        return false;
    for (int i = 0; i <= channel_nb; i++) {
        nbr = find_str(file + index, "\"USR_Teams\":");
        if (nbr < 0)
            return false;
        index += nbr;
    }
    for (int i = 0; i < team_nbr; i++) {
        team = get_balise_content(file + index, i, "\"USR_TEA_UUID\":");
        if (!team)
            return false;
        user_add_team(wrapper->users[channel_nb], my_uuid_from_string(team));
        free(team);
    }
    return true;
}

static bool create_new_user(object_wrapper_t *wrapper, char *file, int channel_nb)
{
    int index = find_str(file, "\"Users\":");
    char *uuid = get_balise_content(file + index, channel_nb, "\"USR_UUID\":");
    char *name = get_balise_content(file + index, channel_nb, "\"USR_Name\":");
    char *status = get_balise_content(file + index, channel_nb, "\"USR_Status\":");
    bool s = (strcmp(status, "online") == 0) ? true : false;

    if (!uuid || !name || !status)
        return false;
    if (!wrapper_adding_user(wrapper, (user_creation_t) {name, s}))
        return false;
    user_edit_uuid(wrapper->users[channel_nb], uuid);
    if (!fill_teams(wrapper, file, index, channel_nb))
        return false;
    free(uuid);
    free(name);
    free(status);
    return true;
}

bool unpack_json_to_wrapper_user(object_wrapper_t *wrapper, char *file)
{
    int user_nbr = get_balise_number(file, 0, "\"User number\":");

    if (user_nbr < 0)
        return false;
    for (int i = 0; i < user_nbr; i++) {
        if (!create_new_user(wrapper, file, i))
            return false;
    }
    return true;
}
