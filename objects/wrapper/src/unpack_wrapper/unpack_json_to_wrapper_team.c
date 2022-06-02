/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_team
*/

/// \file objects/wrapper/src/unpack_wrapper/unpack_json_to_wrapper_team.c
/// \brief Unpack a json file into a wrapper

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

/// \brief Fill channels of a wrapper
/// \param wrap The wrapper to fill
/// \param file The json file
/// \param occ The occurence of the wrapper
/// \return true if the channels are filled, false otherwise
static bool fill_channels(object_wrapper_t *wrap, char *file, int n, int occ)
{
    int nb_c = get_balise_number(file + n, occ, "\"TEA_Channel number\":");
    char *channels = NULL;
    int nbr = 0;

    if (nb_c < 0)
        return false;
    for (int i = 0; i <= occ; i++) {
        nbr = find_str(file + n, "\"TEA_Channels\":");
        if (nbr < 0)
            return false;
        n += nbr;
    }
    for (int i = 0; i < nb_c; i++) {
        channels = get_balise_content(file + n, i, "\"TEA_CHA_UUID\":");
        if (!channels)
            return false;
        team_add_channel(wrap->teams[occ], my_uuid_from_string(channels));
        free(channels);
    }
    return true;
}

/// \brief Fill users of a wrapper
/// \param wrap The wrapper to fill
/// \param file The json file
/// \param occ The occurence of the wrapper
/// \return true if the users are filled, false otherwise
static bool fill_users(object_wrapper_t *wrap, char *file, int n, int occ)
{
    int user_nbr = get_balise_number(file + n, occ, "\"TEA_User number\":");
    char *users = NULL;
    int nbr = 0;

    if (user_nbr < 0)
        return false;
    for (int i = 0; i <= occ; i++) {
        nbr = find_str(file + n, "\"TEA_Users\":");
        if (nbr < 0)
            return false;
        n += nbr;
    }
    for (int i = 0; i < user_nbr; i++) {
        users = get_balise_content(file + n, i, "\"TEA_USR_UUID\":");
        if (!users)
            return false;
        team_add_user(wrap->teams[occ], my_uuid_from_string(users));
        free(users);
    }
    return true;
}

/// \brief Create a team from a json file
/// \param wrapper The wrapper to fill
/// \param file The json file
/// \param occ The occurence of the team
/// \return true if the team is created, false otherwise
static bool create_new_team(object_wrapper_t *wrapper, char *file, int occ)
{
    int index = find_str(file, "\"Teams\":");
    char *name = get_balise_content(file + index, occ, "\"TEA_Name\":");
    char *uuid = get_balise_content(file + index, occ, "\"TEA_UUID\":");
    char *desc = get_balise_content(file + index, occ, "\"TEA_Description\":");

    if (!name || !uuid || !desc)
        return false;
    if (!wrapper_adding_team(wrapper, (team_creation_t) {name, desc}))
        return false;
    team_edit_uuid(wrapper->teams[occ], uuid);
    if (!fill_channels(wrapper, file, index, occ))
        return false;
    if (!fill_users(wrapper, file, index, occ))
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
