/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_message
*/

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

static bool create_new_message(object_wrapper_t *wrapper, char *file, int channel_nb)
{
    int index = find_str(file, "\"Messages\":");
    char *uuid = get_balise_content(file + index, channel_nb, "\"MES_UUID\":");
    char *my_body = get_balise_content(file + index, channel_nb, "\"MES_Body\":");
    char *time = get_balise_content(file + index, channel_nb, "\"MES_Time\":");

    if (!uuid || !my_body || !time)
        return false;
    if (!wrapper_adding_message(wrapper, (message_creation_t) {my_body}))
        return false;
    message_edit_uuid(wrapper->messages[channel_nb], uuid);
    message_edit_time(wrapper->messages[channel_nb], time);
    free(uuid);
    free(my_body);
    free(time);
    return true;
}

bool unpack_json_to_wrapper_message(object_wrapper_t *wrapper, char *file)
{
    int message_nbr = get_balise_number(file, 0, "\"Message number\":");

    if (message_nbr < 0)
        return false;
    for (int i = 0; i < message_nbr; i++) {
        if (!create_new_message(wrapper, file, i))
            return false;
    }
    return true;
}
