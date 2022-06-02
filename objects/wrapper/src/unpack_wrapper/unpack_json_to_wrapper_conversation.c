/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json_to_wrapper_conversation
*/

/// \file objects/wrapper/src/unpack_wrapper/
///unpack_json_to_wrapper_conversation.c
/// \brief Unpack a json file to a wrapper

#include "unpack_json.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"
#include <stdlib.h>

/// \brief Fill participants of a conversation from a json file
/// \param file The json file
/// \param index The index in the json file
/// \param occ The occurence of the conversation
/// \return Participants of the conversation, NULL otherwise
static char **fill_participants(char *file, int index, int occ)
{
    int p_nbr = get_balise_number(file, occ, "\"CON_Participants number\":");
    char **participants = malloc(sizeof(char *) * (p_nbr + 1));
    int nbr = 0;

    if (!participants)
        return NULL;
    for (int i = 0; i <= occ; i++) {
        nbr = find_str(file + index, "\"CON_Participants\":");
        if (nbr < 0)
            return NULL;
        index += nbr;
    }
    for (int i = 0; i < p_nbr; i++) {
        participants[i] = get_balise_content(file + index, i,
        "\"CON_PAR_UUID\":");
        if (!participants[i])
            return NULL;
    }
    participants[p_nbr] = NULL;
    return participants;
}

/// \brief Fill the message of a conversation from a json file
/// \param wrap The wrapper to fill
/// \param file The json file
/// \param n The index in the json file
/// \param occ The occurence of the conversation
/// \return true if the message is filled, false otherwise
static bool fill_messages(object_wrapper_t *wrap, char *file, int n, int occ)
{
    int nb_message = get_balise_number(file, occ, "\"CON_Messages number\":");
    char *messages = NULL;
    int nbr = 0;

    if (nb_message < 0)
        return false;
    for (int i = 0; i <= occ; i++) {
        nbr = find_str(file + n, "\"CON_Messages\":");
        if (nbr < 0)
            return false;
        n += nbr;
    }
    for (int i = 0; i < nb_message; i++) {
        if (!(messages = get_balise_content(file + n, i, "\"CON_MES_UUID\":")))
            return false;
        conversation_add_message(wrap->conversations[occ],
        my_uuid_from_string(messages));
        free(messages);
    }
    return true;
}

/// \brief Create a conversation from a json file
/// \param wrap The wrapper
/// \param file The json file
/// \param oc The occurence of the conversation
/// \return true if the conversation was created, false otherwise
static bool create_new_conversation(object_wrapper_t *wrap, char *file, int oc)
{
    int index = find_str(file, "\"Conversation\":");
    char *uuid = get_balise_content(file + index, oc, "\"CON_UUID\":");
    char **participants = fill_participants(file, index, oc);

    if (!uuid || !participants) {
        return false;
    }
    if (!wrapper_adding_conversation(wrap, (conversation_creation_t) {
        my_uuid_from_string(participants[0]),
        my_uuid_from_string(participants[1])})) {
        return false;
    }
    if (!fill_messages(wrap, file, index, oc)) {
        return false;
    }
    conversation_edit_uuid(wrap->conversations[oc], uuid);
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
