/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** compute_command
*/

/// \file server/src/core/compute_command.c

#include <stdlib.h>
#include "cli_commands.h"
#include "rcodes.h"

/// \brief Add a character to the command at index.
/// \param command The buffer to add the character to.
/// \param index The index to add the character to.
/// \param c The character to add.
/// \return The new command.
static char *add_char(char *command, int index, char c)
{
    command = realloc(command, sizeof(char) * (index + 2));
    command[index] = c;
    command[index + 1] = '\0';
    return command;
}

/// \brief Format the flexible argument part of the command to strict
/// argument format.
/// \param char * The flexible command.
/// \param int The index in the flexible command.
/// \param int The index in the strict command.
/// \return char * The strict command.
static char *format_arguments(char *command, char *new_command, int cmd_i,
int new_cmd_i)
{
    int copy = 0;
    char c = 0;

    for (; command[cmd_i]; cmd_i++) {
        c = command[cmd_i];
        if (c == '"' && copy)
            new_command = add_char(new_command, new_cmd_i, '"');
        if (c == '"' && !copy)
            new_command = add_char(new_command, new_cmd_i, ' ');
        if (c == '"') {
            copy = (copy) ? 0 : 1;
            new_cmd_i++;
        }
        if (copy) {
            new_command = add_char(new_command, new_cmd_i, c);
            new_cmd_i++;
        }
    }
    command[new_cmd_i] = '\0';
    return new_command;
}

/// \brief Format the command from flexible command format to strict
/// command format.
/// \param char * Flexible command.
/// \return char * Strict command.
static char *format_command(char *command)
{
    int cmd_i = 0;
    int new_cmd_i = 0;
    char *new_command = NULL;

    if (!command)
        return NULL;
    for (; command[cmd_i] && command[cmd_i] != '/'; cmd_i++);
    for (; command[cmd_i] && command[cmd_i] != ' '; cmd_i++) {
        new_command = realloc(new_command, (new_cmd_i + 2) * sizeof(char));
        new_command[new_cmd_i] = command[cmd_i];
        new_command[new_cmd_i + 1] = '\0';
        new_cmd_i++;
    }
    return format_arguments(command, new_command, cmd_i, new_cmd_i);
}

int compute_command(char *command, user_list_t *users,
server_data_t *server_data)
{
    char *tmp = format_command(command);
    cli_command_t *cmd = convert_command_to_structure(tmp, users);

    if (cmd == NULL)
        return (-1);
    call_command(cmd, users, server_data);
    free(cmd->name);
    if (cmd->arguments) {
        for (int i = 0; cmd->arguments[i]; i++) {
            free(cmd->arguments[i]);
        }
        free(cmd->arguments);
    }
    free(cmd);
    free(command);
    free(tmp);
    return (0);
}
