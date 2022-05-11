/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** check_command
*/

/// \file server/src/parser/check_command.c

#include "cli_commands.h"

/// \brief Calcul the len of the tab
/// \param char **tab
/// \return The length of the tab
static int count_tab_len(char **tab)
{
    int arg_count = 0;

    while (tab[arg_count]) {
        arg_count++;
    }
    return (arg_count);
}

/// \brief Find if the command from client is valid
/// \param char ** arguments of the command
/// \param cli_command_t The command that will be called
/// \return 1 if it find a valid command, or 0 otherwise
static int find_command(char **arguments, cli_command_t *commands)
{
    int arg_count = count_tab_len(arguments);

    if (strcmp(arguments[0], commands->name) == 0) {
        if (arg_count == count_tab_len(commands->arguments) + 1) {
            return (1);
        }
    }
    return (0);
}

int check_arguments(char **arguments)
{
    cli_command_t *commands = get_cli_commands();

    for (int i = 0; i < 14; i++) {
        if (find_command(arguments, &commands[i])) {
            return (1);
        }
    }
    return (0);
}
