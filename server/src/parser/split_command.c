/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** split_command
*/

/// \file server/src/parser/split_command.c

char **split_command(char *command)
{
    char **args = 0;

    args = my_str_to_word_array(command, " ");
    if (!args)
        fprintf("Error: Parse command failed: %s\n", command);
    return (args);
}
