/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_conversation
*/

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

static char **fill_participants(char *file, int index, int channel_nb)
{
    int participants_nbr = get_balise_number(file, channel_nb, "\"CON_Participants number\":");
    char **participants = malloc(sizeof(char *) * (participants_nbr + 1));
    int nbr = 0;

    if (!participants)
        return NULL;
    for (int i = 0; i <= channel_nb; i++) {
        nbr = find_str(file + index, "\"CON_Participants\":");
        if (nbr < 0)
            return NULL;
        index += nbr;
    }
    for (int i = 0; i < participants_nbr; i++) {
        participants[i] = get_balise_content(file + index, i, "\"CON_PAR_UUID\":");
        if (!participants[i])
            return NULL;
    }
    participants[participants_nbr] = NULL;
    return participants;
}

static bool fill_messages(object_wrapper_t *wrapper, char *file, int index, int channel_nb)
{
    int nb_channel = get_balise_number(file, channel_nb, "\"CON_Messages number\":");
    char *messages = NULL;
    int nbr = 0;

    if (nb_channel < 0)
        return false;
    for (int i = 0; i <= channel_nb; i++) {
        nbr = find_str(file + index, "\"CON_Messages\":");
        if (nbr < 0)
            return false;
        index += nbr;
    }
    for (int i = 0; i < nb_channel; i++) {
        messages = get_balise_content(file + index, i, "\"CON_MES_UUID\":");
        if (!messages)
            return false;
        conversation_add_message(wrapper->conversations[channel_nb], my_uuid_from_string(messages));
        free(messages);
    }
    return true;
}

static bool create_new_conversation(object_wrapper_t *wrapper, char *file, int channel_nb)
{
    int index = find_str(file, "\"Conversation\":");
    char *uuid = get_balise_content(file + index, channel_nb, "\"CON_UUID\":");
    char **participants = fill_participants(file, index, channel_nb);

    if (!uuid || !participants) {
        return false;
    }
    if (!wrapper_adding_conversation(wrapper, (conversation_creation_t) {
        my_uuid_from_string(participants[0]),
        my_uuid_from_string(participants[1])})) {
        return false;
    }
    if (!fill_messages(wrapper, file, index, channel_nb)) {
        return false;
    }
    conversation_edit_uuid(wrapper->conversations[channel_nb], uuid);
    return true;
}

bool unpack_json_to_wrapper_conversation(object_wrapper_t *wrapper, char *file)
{
    int nbr = get_balise_number(file, 0, "\"Conversation number\":");

    if (nbr < 0) {
        return false;
    }
    for (int i = 0; i < nbr; i++) {
        if (!create_new_conversation(wrapper, file, i)) {
            return false;
        }
    }
    return true;
}
