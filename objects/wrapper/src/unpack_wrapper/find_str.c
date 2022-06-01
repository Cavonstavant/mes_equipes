/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** find_str
*/

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
