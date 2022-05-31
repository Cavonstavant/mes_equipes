/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** parser
*/

/// \file server/src/core/include/cli_commands.h

#ifndef CLI_COMMANDS_H_
    #define CLI_COMMANDS_H_

    #include "server.h"

    /// \brief The number of command available.
    #define COMMAND_NUMBER 14

/// \brief structure to store available client command.
typedef struct cli_command_s {
    /// \brief char * The name of the command.
    char *name;
    /// \brief char ** Arguments for the command.
    char **arguments;
    /// \brief void * Function to call.
    bool (*function)(struct cli_command_s *, user_list_t *, server_data_t *);
} cli_command_t;

bool command_help(cli_command_t *, user_list_t *, server_data_t *);
bool command_info(cli_command_t *, user_list_t *, server_data_t *);
bool command_list(cli_command_t *, user_list_t *, server_data_t *);
bool command_create(cli_command_t *, user_list_t *, server_data_t *);
bool command_use(cli_command_t *, user_list_t *, server_data_t *);
bool command_unsubscribe(cli_command_t *, user_list_t *, server_data_t *);
bool command_subscribe(cli_command_t *, user_list_t *, server_data_t *);
bool command_subscribed(cli_command_t *, user_list_t *, server_data_t *);
bool command_messages(cli_command_t *, user_list_t *, server_data_t *);
bool command_send(cli_command_t *, user_list_t *, server_data_t *);
bool command_user(cli_command_t *, user_list_t *, server_data_t *);
bool command_users(cli_command_t *, user_list_t *, server_data_t *);
bool command_logout(cli_command_t *, user_list_t *, server_data_t *);
bool command_login(cli_command_t *, user_list_t *, server_data_t *);

/// \brief This function get the commands static const defined in
/// cli_command.c.
/// \return const cli_command_t * An array of available commands.
const cli_command_t *get_cli_commands();

/// \brief This function get a cli_commands depending of it's name.
/// \param char * The called command to find the structure corresponding of the
/// correct structure.
/// \return const cli_command_t * Pointer to the corresponding cli_command.
const cli_command_t *get_cli_command_by_name(char *command);

/// \brief This function get a command, and parse it to fill a structure.
/// \param char *command to be convert in structure.
/// \return A cli_command_t * structure to be used after.
cli_command_t *convert_command_to_structure(char *command, user_list_t *users);

/// \brief This function call the function store on the structure passed as
/// parameter.
/// \param cli_command_t The structure which contains the function to be call.
/// \return 0, or -1 if an error occurs.
int call_command(cli_command_t *command, user_list_t *, server_data_t *);

/// \brief This function fill the arguments of the called command in a array
/// of char *.
/// \param char *The command to be parse.
/// \param char *The name of the called command.
/// \return A array of char * which contains all arguments if it's OK, or NULL
/// if an error occurs.
char **fill_command_arguments(char *command, char *name, user_list_t *users);

#endif /* !PARSER_H_ */
