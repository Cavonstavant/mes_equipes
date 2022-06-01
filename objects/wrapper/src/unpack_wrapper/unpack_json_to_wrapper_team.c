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

static void fill_channels(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int channel_nbr = get_balise_number(file + index, channel_nb, "\"TEA_Channel number\":");
    char **channels = malloc(sizeof(char *) * (channel_nbr + 1));

    if (!channels)
        return;
    index += find_str(file + index, "\"TEA_Channels\":");
    for (int i = 0; i < channel_nb; i++)
        index += find_str(file + index, "\"TEA_Channels\":");
    for (int i = 0; i < channel_nbr; i++)
        channels[i] = get_balise_content(file + index, i, "\"TEA_CHA_UUID\":");
    channels[channel_nbr] = NULL;
    for (int i = 0; i < channel_nbr; i++)
        team_add_channel(wrapper->teams[channel_nbr],
        my_uuid_from_string(channels[i]));
    for (int i = 0; channels[i]; i++)
        free(channels[i]);
    free(channels);
}

static void fill_users(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int user_nbr = get_balise_number(file + index, channel_nb, "\"TEA_User number\":");
    char **users = NULL;

    if (!users)
        return;
    index += find_str(file + index, "\"TEA_Users\":");
    for (int i = 0; i < channel_nb; i++)
        index += find_str(file + index, "\"TEA_Users\":");
    for (int i = 0; i < user_nbr; i++)
        users[i] = get_balise_content(file + index, i, "\"\":");
    users[user_nbr] = NULL;
    for (int i = 0; i < user_nbr; i++)
        team_add_channel(wrapper->teams[user_nbr],
        my_uuid_from_string(users[i]));
    for (int i = 0; users[i]; i++)
        free(users[i]);
    free(users);
}

static void create_new_team(object_wrapper_t *wrapper, char *file, int channel_nb)
{
    int index = find_str(file, "\"Teams\":");
    char *name = get_balise_content(file + index, channel_nb, "\"TEA_Name\":");
    char *uuid = get_balise_content(file + index, channel_nb, "\"TEA_UUID\":");
    char *desc = get_balise_content(file + index, channel_nb, "\"TEA_Description\":");

    fill_channels(wrapper, file, index, channel_nb);
    fill_users(wrapper, file, index, channel_nb);
    wrapper_adding_team(wrapper, (team_creation_t) {
        name, desc
    });
    team_edit_uuid(wrapper->teams[channel_nb], uuid);
    free(name);
    free(uuid);
    free(desc);
}

void unpack_json_to_wrapper_team(object_wrapper_t *wrapper, char *file)
{
    int channel_nbr = get_balise_number(file, 0, "\"Team number\":");

    for (int i = 0; i < channel_nbr; i++) {
        create_new_team(wrapper, file, i);
    }
}
