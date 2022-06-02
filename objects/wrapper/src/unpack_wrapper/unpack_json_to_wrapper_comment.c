/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_comment
*/

/// \file objects/wrapper/src/unpack_wrapper/unpack_json_to_wrapper_comment.c
/// \brief Unpack a json file into a wrapper

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

/// \brief Create a comment from a json file
/// \param wrap The wrapper
/// \param file The json file
/// \param occ The occurence of the comment
/// \return true if the comment was created, false otherwise
static bool create_new_comment(object_wrapper_t *wrap, char *file, int occ)
{
    int index = find_str(file, "\"Comments\":");
    char *uuid = get_balise_content(file + index, occ, "\"COM_UUID\":");
    char *parent = get_balise_content(file + index, occ, "\"COM_Parent\":");
    char *author = get_balise_content(file + index, occ, "\"COM_Author\":");
    char *my_body = get_balise_content(file + index, occ, "\"COM_Body\":");
    char *time = get_balise_content(file + index, occ, "\"COM_Time\":");

    if (!uuid || !parent || !author || !my_body || !time)
        return false;
    if (!wrapper_adding_comment(wrap, (comment_creation_t) {
        my_body, my_uuid_from_string(parent), my_uuid_from_string(author)}))
        return false;
    comment_edit_uuid(wrap->comments[occ], uuid);
    comment_edit_time(wrap->comments[occ], time);
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
