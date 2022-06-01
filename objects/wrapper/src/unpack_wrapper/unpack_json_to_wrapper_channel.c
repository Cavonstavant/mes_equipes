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

static void fill_child(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int nb_child = get_balise_number(file + index, channel_nb, "\"CHA_Child number\":");
    char **child = malloc(sizeof(char *) * (nb_child + 1));

    if (!child)
        return;
    index += find_str(file + index, "\"CHA_Child\":");
    for (int i = 0; i < channel_nb; i++)
        index += find_str(file + index, "\"CHA_Child\":");
    for (int i = 0; i < nb_child; i++)
        child[i] = get_balise_content(file + index, i, "\"CHA_CHI_UUID\":");
    child[nb_child] = NULL;
    for (int i = 0; i < nb_child; i++)
        channel_add_threads(wrapper->channels[channel_nb],
        my_uuid_from_string(child[i]));
    for (int i = 0; child[i]; i++)
        free(child[i]);
    free(child);
}

static void create_new_channel(object_wrapper_t *wrapper, char *file, int channel_nb)
{
    int index = find_str(file, "\"Channels\":");
    char *name = get_balise_content(file + index, channel_nb, "\"CHA_Name\":");
    char *desc = get_balise_content(file + index, channel_nb, "\"CHA_Description\":");
    char *my_uuid = get_balise_content(file + index, channel_nb, "\"CHA_UUID\":");
    char *parent = get_balise_content(file + index, channel_nb, "\"CHA_Parent\":");

    wrapper_adding_channel(wrapper, (channel_creation_t){
        name, desc, my_uuid_from_string(parent)
    });
    fill_child(wrapper, file, index, channel_nb);
    channel_edit_uuid(wrapper->channels[channel_nb], my_uuid);
    free(name);
    free(desc);
    free(my_uuid);
    free(parent);
}

void unpack_json_to_wrapper_channel(object_wrapper_t *wrapper, char *file)
{
    int channel_nbr = get_balise_number(file, 0, "\"Channel number\":");

    for (int i = 0; i < channel_nbr; i++) {
        create_new_channel(wrapper, file, i);
    }
}
