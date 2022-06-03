/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_user
*/

/// \file objects/wrapper/src/unpack_wrapper/unpack_json_to_wrapper_user.c
/// \brief Unpack a json file into a wrapper

#include "logging_server.h"
#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

/// \brief Fill teams from a json file
/// \param wrapper The wrapper to fill
/// \param file The json file
/// \param occ The occurence of the wrapper
/// \return true if the teams are filled, false otherwise
static bool fill_teams(object_wrapper_t *wrapper, char *file, int n, int occ)
{
    int team_nbr = get_balise_number(file + n, occ, "\"USR_Team number\":");
    char *team = NULL;
    int nbr = 0;

    if (team_nbr < 0)
        return false;
    for (int i = 0; i <= occ; i++) {
        nbr = find_str(file + n, "\"USR_Teams\":");
        if (nbr < 0)
            return false;
        n += nbr;
    }
    for (int i = 0; i < team_nbr; i++) {
        team = get_balise_content(file + n, i, "\"USR_TEA_UUID\":");
        if (!team)
            return false;
        user_add_team(wrapper->users[occ], my_uuid_from_string(team));
        free(team);
    }
    return true;
}

/// \brief Create user from a json file
/// \param wrapper The wrapper to fill
/// \param file The json file
/// \param occ The occurence of the user
/// \return true if the user is created, false otherwise
static bool create_new_user(object_wrapper_t *wrapper, char *file, int occ)
{
    int index = find_str(file, "\"Users\":");
    char *uuid = get_balise_content(file + index, occ, "\"USR_UUID\":");
    char *name = get_balise_content(file + index, occ, "\"USR_Name\":");
    char *status = get_balise_content(file + index, occ, "\"USR_Status\":");
    bool s = false;

    if (!uuid || !name || !status)
        return false;
    if (!wrapper_adding_user(wrapper, (user_creation_t) {name, s}))
        return false;
    server_event_user_loaded(wrapper->users[occ]->uuid->uuid.repr + 4,
    wrapper->users[occ]->name);
    user_edit_uuid(wrapper->users[occ], uuid);
    if (!fill_teams(wrapper, file, index, occ))
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
