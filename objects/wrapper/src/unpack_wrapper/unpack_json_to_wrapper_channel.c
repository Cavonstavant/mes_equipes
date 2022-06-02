/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_channel
*/

/// \file objects/wrapper/src/unpack_wrapper/unpack_json_to_wrapper_channel.c
/// \brief Unpack a json file into a wrapper

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

/// \brief Fill a child of a channel with the data from a json file
/// \param wrap The wrapper to fill
/// \param file The json file
/// \param n The index of the child
/// \param c_nb The number of the channel to skip
static bool fill_child(object_wrapper_t *wrap, char *file, int n, int c_nb)
{
    int nb_child = get_balise_number(file + n, c_nb, "\"CHA_Child number\":");
    char *child = NULL;
    int nbr = 0;

    if (nb_child < 0)
        return false;
    for (int i = 0; i <= c_nb; i++) {
        nbr = find_str(file + n, "\"CHA_Child\":");
        if (nbr < 0)
            return false;
        n += nbr;
    }
    for (int i = 0; i < nb_child; i++) {
        child = get_balise_content(file + n, i, "\"CHA_CHI_UUID\":");
        if (!child)
            return false;
        channel_add_threads(wrap->channels[c_nb], my_uuid_from_string(child));
        free(child);
    }
    return true;
}

/// \brief Create a channel from a json file
/// \param wrap The wrapper to fill
/// \param file The json file
/// \param c_nb The number of the channel to create
/// \return true if the channel was created, false otherwise
static bool create_new_channel(object_wrapper_t *wrap, char *file, int c_nb)
{
    int idx = find_str(file, "\"Channels\":");
    char *name = get_balise_content(file + idx, c_nb, "\"CHA_Name\":");
    char *desc = get_balise_content(file + idx, c_nb, "\"CHA_Description\":");
    char *my_uuid = get_balise_content(file + idx, c_nb, "\"CHA_UUID\":");
    char *parent = get_balise_content(file + idx, c_nb, "\"CHA_Parent\":");

    if (!name || !desc || !my_uuid || !parent)
        return false;
    if (wrap_adding_channel(wrap, (channel_creation_t) {
        name, desc, my_uuid_from_string(parent)
    }) == false)
        return false;
    if (fill_child(wrap, file, idx, c_nb) == false)
        return false;
    channel_edit_uuid(wrap->channels[c_nb], my_uuid);
    free(name);
    free(desc);
    free(my_uuid);
    free(parent);
    return true;
}

bool unpack_json_to_wrapper_channel(object_wrapper_t *wrapper, char *file)
{
    int channel_nbr = get_balise_number(file, 0, "\"Channel number\":");

    if (channel_nbr < 0)
        return false;
    for (int i = 0; i < channel_nbr; i++) {
        if (create_new_channel(wrapper, file, i) == false)
            return false;
    }
    return true;
}
