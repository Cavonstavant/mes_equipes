/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** get_balise
*/

/// \file objects/wrapper/src/unpack_wrapper/get_balise.c

#include "unpack_json.h"
#include <stdlib.h>

int get_balise_number(char *file, int channel_nb, char *balise)
{
    int index = 0;
    int nbr = find_str(file, balise);

    if (nbr < 0)
        return -1;
    for (int i = 0; i < channel_nb; i++) {
        index += nbr;
        nbr = find_str(file + index, balise);
        if (nbr < 0)
            return -1;
    }
    index += nbr;
    nbr = atoi(file + index);
    return nbr;
}

char *get_balise_content(char *file, int channel_nb, char *balise)
{
    int index = 0;
    char *name = NULL;
    int nbr = find_str(file, balise);

    if (nbr < 0)
        return NULL;
    for (int i = 0; i < channel_nb; i++) {
        index += nbr;
        nbr = find_str(file + index, balise);
        if (nbr < 0)
            return NULL;
    }
    index += nbr + 1;
    for (nbr = 0; file[index + nbr] != '"'; nbr++);
    name = malloc(sizeof(char) * (nbr + 1));
    if (!name)
        return NULL;
    strncpy(name, file + index, nbr);
    name[nbr] = '\0';
    return name;
}
