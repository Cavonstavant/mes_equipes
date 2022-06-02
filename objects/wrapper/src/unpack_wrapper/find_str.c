/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** find_str
*/

/// \file objects/wrapper/src/unpack_wrapper/find_str.c
/// \brief Find a string in a json file

#include <string.h>

int find_str(char *file, char *to_find)
{
    size_t index = 0;

    while (strncmp(file + index, to_find, strlen(to_find)) != 0) {
        index++;
        if (index >= strlen(file))
            return -1;
    }
    return index + strlen(to_find);
}
