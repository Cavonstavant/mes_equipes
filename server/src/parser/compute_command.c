/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command
*/

#include <stdio.h>

static void free_args(char **args)
{
    int index = 0;

    while (args[index]) {
        free(args[index]);
        index++;
    }
    free(args);
}

int compute_command(const char *command)
{
    char **args = split_command(command);
    int retval = 0;

    if (!args) {
        return (-1);
    }
    retval = check_arguments_validity(args);
    if (retval < 0) {
        return (-1);
    }
    retval = call_command_function(args);
    if (retval < 0) {
        return (-1);
    }
    free_args(args);
    return (0);
}
