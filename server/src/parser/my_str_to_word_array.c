/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** my_str_to_word_array
*/

/// \file server/src/parser/my_str_to_word_array.c

#include <stdlib.h>

static int find_separator(char c, char *separators)
{
    for (int i = 0; separators[i]; i++) {
        if (c == separators[i])
            return (1);
    }
    return (0);
}

static int skip_separator(char *command, char *separator)
{
    int count = 0;

    for (int i = 0; command && separator[i]; i++) {
        if (command[0] == separator[i]) {
            count += skip_separator(command + 1, separator);
            return (count + 1);
        }
    }
    return (count);
}

static int count_args(char *command, char *separators)
{
    int count = 1;
    int i = 0;

    for (i = 0; command[i]; i++) {
        if (find_separator(command[i], separators)) {
            i += skip_separator(command + i, separators);
            count++;
        }
    }
    if (find_separator(command[i - 2], separators)) {
        count--;
    }
    return (count);
}

static int calcul_arg_len(char *command, char *separators)
{
    int len = 0;

    while (command && command[len]) {
        if (find_separator(command[len], separators))
            return (len);
        len++;
    }
    return (len);
}

char **my_str_to_word_array(char *command, char *separators)
{
    char **tab = NULL;
    int nb_args = count_args(command, separators);
    int arg_len = 0;

    tab = malloc(sizeof(char *) * (nb_args + 1));
    if (!tab)
        return (NULL);
    for (int i = 0; i < nb_args; i++) {
        arg_len = calcul_arg_len(command, separators);
        tab[i] = malloc(sizeof(char) * (arg_len + 1));
        if (!tab[i])
            return (NULL);
        strncpy(tab[i], command, arg_len);
        command += arg_len;
        command += skip_separator(command, separators);
    }
    tab[nb_args] = NULL;
    return (tab);
}
