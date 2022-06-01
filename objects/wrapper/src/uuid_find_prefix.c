/*
** EPITECH PROJECT, 2022
** Project
** File description:
** uuid_find_prefix
*/

/// \file objects/wrapper/uuid_find_prefix.c

#include "object_wrapper.h"
#include <stdlib.h>

///
/// \brief Find a user uuid with prefix
///
/// \param wrapper Wrapper object
/// \param repr Uuid without prefix
/// \return char* Prefix
///
static char *find_a_uuid_user(object_wrapper_t *wrapper, char *repr)
{
    for (int i = 0; i < wrapper->user_n; i++)
        if (my_uuid_cmp_not(wrapper->users[i]->uuid, repr))
            return "USR_";
    return "UKN_";
}

char *find_a_uuid(object_wrapper_t *wrapper, char *repr)
{
    for (int i = 0; i < wrapper->channel_n; i++)
        if (my_uuid_cmp_not(wrapper->channels[i]->uuid, repr))
            return "CHA_";
    for (int i = 0; i < wrapper->comment_n; i++)
        if (my_uuid_cmp_not(wrapper->comments[i]->uuid, repr))
            return "COM_";
    for (int i = 0; i < wrapper->conversation_n; i++)
        if (my_uuid_cmp_not(wrapper->conversations[i]->uuid, repr))
            return "CON_";
    for (int i = 0; i < wrapper->message_n; i++)
        if (my_uuid_cmp_not(wrapper->messages[i]->uuid, repr))
            return "DMS_";
    for (int i = 0; i < wrapper->team_n; i++)
        if (my_uuid_cmp_not(wrapper->teams[i]->uuid, repr))
            return "TEM_";
    for (int i = 0; i < wrapper->thread_n; i++)
        if (my_uuid_cmp_not(wrapper->threads[i]->uuid, repr))
            return "THR_";
    return find_a_uuid_user(wrapper, repr);
}

my_uuid_t *my_uuid_fstring(char *repr, object_wrapper_t *wrapper)
{
    my_uuid_t *uuid = my_uuid_init(TEM_);
    char *new = malloc(sizeof(char) * (strlen(repr) + 5));
    char *prefix = NULL;

    if (new == NULL)
        return NULL;
    if (strlen(repr) != 36)
        return NULL;
    new[0] = '\0';
    prefix = find_a_uuid(wrapper, repr);
    if (!strcmp(prefix, "UKN_"))
        return NULL;
    strcat(new, prefix);
    strcat(new, repr);
    if (my_uuid_edit_content(uuid, new) == -1)
        return NULL;
    free(new);
    return uuid;
}