/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_thread
*/

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

static bool fill_comments(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int comment_nbr = get_balise_number(file + index, channel_nb, "\"THR_Comment number\":");
    char *comments = NULL;
    int nbr = 0;

    if (comment_nbr < 0)
        return false;
    for (int i = 0; i <= channel_nb; i++) {
        nbr = find_str(file + index, "\"THR_Comments\":");
        if (nbr < 0)
            return false;
        index += nbr;
    }
    for (int i = 0; i < comment_nbr; i++) {
        comments = get_balise_content(file + index, channel_nb, "\"THR_COM_UUID\":");
        if (!comments)
            return false;
        thread_add_comment(wrapper->threads[channel_nb], my_uuid_from_string(comments));
        free(comments);
    }
    return true;
}

static bool create_new_thread(object_wrapper_t *wrapper, char *file, int i)
{
    int index = find_str(file, "\"Threads\":");
    char *uuid = get_balise_content(file + index, i, "\"THR_UUID\":");
    char *parent = get_balise_content(file + index, i, "\"THR_Parent\":");
    char *author = get_balise_content(file + index, i, "\"THR_Author\":");
    char *name = get_balise_content(file + index, i, "\"THR_Name\":");
    char *body = get_balise_content(file + index, i, "\"THR_Body\":");
    char *time = get_balise_content(file + index, i, "\"THR_Time\":");

    if (!uuid || !parent || !author || !name || !body || !time)
        return false;
    if (!wrapper_adding_thread(wrapper, (thread_creation_t) {
        name, body, my_uuid_from_string(author), my_uuid_from_string(parent)
    }))
        return false;;
    thread_edit_uuid(wrapper->threads[i], uuid);
    thread_edit_time(wrapper->threads[i], time);
    if (!fill_comments(wrapper, file, index, i))
        return false;
    free(uuid);
    free(parent);
    free(author);
    free(name);
    free(body);
    free(time);
    return true;
}

bool unpack_json_to_wrapper_thread(object_wrapper_t *wrapper, char *file)
{
    int thread_nbr = get_balise_number(file, 0, "\"Thread number\":");

    if (thread_nbr < 0)
        return false;
    for (int i = 0; i < thread_nbr; i++) {
        if (!create_new_thread(wrapper, file, i))
            return false;
    }
    return true;
}
