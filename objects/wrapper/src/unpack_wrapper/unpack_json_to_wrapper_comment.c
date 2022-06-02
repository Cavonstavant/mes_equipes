/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_comment
*/

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

static bool create_new_comment(object_wrapper_t *wrapper, char *file, int channel_nb)
{
    int index = find_str(file, "\"Comments\":");
    char *uuid = get_balise_content(file + index, channel_nb, "\"COM_UUID\":");
    char *parent = get_balise_content(file + index, channel_nb, "\"COM_Parent\":");
    char *author = get_balise_content(file + index, channel_nb, "\"COM_Author\":");
    char *my_body = get_balise_content(file + index, channel_nb, "\"COM_Body\":");
    char *time = get_balise_content(file + index, channel_nb, "\"COM_Time\":");

    if (!uuid || !parent || !author || !my_body || !time)
        return false;
    if (!wrapper_adding_comment(wrapper, (comment_creation_t) {
        my_body, my_uuid_from_string(parent), my_uuid_from_string(author)}))
        return false;
    comment_edit_uuid(wrapper->comments[channel_nb], uuid);
    comment_edit_time(wrapper->comments[channel_nb], time);
    free(uuid);
    free(parent);
    free(author);
    free(my_body);
    free(time);
    return true;
}

bool unpack_json_to_wrapper_comment(object_wrapper_t *wrapper, char *file)
{
    int comment_nbr = get_balise_number(file, 0, "\"Comment number\":");

    if (comment_nbr < 0)
        return false;
    for (int i = 0; i < comment_nbr; i++) {
        if (!create_new_comment(wrapper, file, i))
            return false;
    }
    return true;
}
