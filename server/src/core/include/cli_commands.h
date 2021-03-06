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
    #include "rcodes.h"

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

/// \brief The help command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_help(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The info command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_info(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The list command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_list(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The create command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_create(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The use command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_use(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The unsubscribe command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_unsubscribe(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The subscribe command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_subscribe(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The subscribed command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_subscribed(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The messages command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_messages(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The send command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_send(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The user command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_user(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The users command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_users(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The logout command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_logout(cli_command_t *, user_list_t *, server_data_t *);

/// \brief The login command.
/// \param cli_command The command to call.
/// \param user_list The list of users.
/// \param server_data The server data.
/// \return true if the command is valid, false otherwise.
bool command_login(cli_command_t *, user_list_t *, server_data_t *);

/// \brief This function get the commands static const defined in
/// cli_command.c.
/// \return const cli_command_t * An array of available commands.
const cli_command_t *get_cli_commands(void);

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

/// \brief Reset the localisation of an user
/// \param user User info
/// \param print Last command of use
/// \return true When operation succeed
/// \return false When operation failed
static inline bool command_use_empty(user_list_t *user, bool print)
{
    user->loc = NULL;
    if (print)
        print_retcode(200, NULL, user->user_peer, true);
    return true;
}

#endif /* !PARSER_H_ */
