/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_thread
*/

/// \file objects/wrapper/src/unpack_wrapper/unpack_json_to_wrapper_thread.c
/// \brief Unpack a json file into a wrapper
#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

/// \brief Fill a comment of a thread with a json file
/// \param wrap The wrapper to fill
/// \param file The json file
/// \param n The index in the json file
/// \param occ The occurence of the thread
/// \return true if the comment is filled, false otherwise
static bool fill_comments(object_wrapper_t *wrap, char *file, int n, int occ)
{
    int c_nb = get_balise_number(file + n, occ, "\"THR_Comment number\":");
    char *comments = NULL;
    int nbr = 0;

    if (c_nb < 0)
        return false;
    for (int i = 0; i <= occ; i++) {
        nbr = find_str(file + n, "\"THR_Comments\":");
        if (nbr < 0)
            return false;
        n += nbr;
    }
    for (int i = 0; i < c_nb; i++) {
        comments = get_balise_content(file + n, occ, "\"THR_COM_UUID\":");
        if (!comments)
            return false;
        thread_add_comment(wrap->threads[occ], my_uuid_from_string(comments));
        free(comments);
    }
    return true;
}

/// \brief Create a thread with a json file part two
/// \param wrapper The wrapper to fill
/// \param file The json file
/// \param i The index in the json file
/// \param index The index of the thread
/// \return true if the thread is created, false otherwise
static bool create_new_thread_part_two(object_wrapper_t *wrapper, char *file,
int i, int index)
{
    char *uuid = get_balise_content(file + index, i, "\"THR_UUID\":");
    char *time = get_balise_content(file + index, i, "\"THR_Time\":");

    if (!time || !uuid)
        return false;
    thread_edit_uuid(wrapper->threads[i], uuid);
    thread_edit_time(wrapper->threads[i], time);
    free(uuid);
    free(time);
    return true;
}

/// \brief Create a thread with a json file
/// \param wrapper The wrapper to fill
/// \param file The json file
/// \param i The index in the json file
/// \return true if the thread is created, false otherwise
static bool create_new_thread(object_wrapper_t *wrapper, char *file, int i)
{
    int index = find_str(file, "\"Threads\":");
    char *parent = get_balise_content(file + index, i, "\"THR_Parent\":");
    char *author = get_balise_content(file + index, i, "\"THR_Author\":");
    char *name = get_balise_content(file + index, i, "\"THR_Name\":");
    char *body = get_balise_content(file + index, i, "\"THR_Body\":");

    if (!parent || !author || !name || !body)
        return false;
    if (!wrapper_adding_thread(wrapper, (thread_creation_t) {
        name, body, my_uuid_from_string(author), my_uuid_from_string(parent)
    }))
        return false;;
    if (!fill_comments(wrapper, file, index, i))
        return false;
    free(parent);
    free(author);
    free(name);
    free(body);
    return create_new_thread_part_two(wrapper, file, i, index);
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
