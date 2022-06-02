/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_channel
*/

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

static bool fill_child(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int nb_child = get_balise_number(file + index, channel_nb, "\"CHA_Child number\":");
    char *child = NULL;
    int nbr = 0;

    if (nb_child < 0)
        return false;
    for (int i = 0; i <= channel_nb; i++) {
        nbr = find_str(file + index, "\"CHA_Child\":");
        if (nbr < 0)
            return false;
        index += nbr;
    }
    for (int i = 0; i < nb_child; i++) {
        child = get_balise_content(file + index, i, "\"CHA_CHI_UUID\":");
        if (!child)
            return false;
        channel_add_threads(wrapper->channels[channel_nb], my_uuid_from_string(child));
        free(child);
    }
    return true;
}

static bool create_new_channel(object_wrapper_t *wrapper, char *file, int channel_nb)
{
    int index = find_str(file, "\"Channels\":");
    char *name = get_balise_content(file + index, channel_nb, "\"CHA_Name\":");
    char *desc = get_balise_content(file + index, channel_nb, "\"CHA_Description\":");
    char *my_uuid = get_balise_content(file + index, channel_nb, "\"CHA_UUID\":");
    char *parent = get_balise_content(file + index, channel_nb, "\"CHA_Parent\":");

    if (!name || !desc || !my_uuid || !parent)
        return false;
    if (wrapper_adding_channel(wrapper, (channel_creation_t){
        name, desc, my_uuid_from_string(parent)
    }) == false)
        return false;
    if (fill_child(wrapper, file, index, channel_nb) == false)
        return false;
    channel_edit_uuid(wrapper->channels[channel_nb], my_uuid);
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
