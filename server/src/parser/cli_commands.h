/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** parser
*/

/// \file server/src/cli_commands.h

#ifndef CLI_COMMANDS_H_
    #define CLI_COMMANDS_H_

    #define COMMAND_NUMBER 14
/// \brief structure to store available client command.
typedef struct cli_command_s {
    /// \brief char * The name of the command.
    char *name;
    /// \brief char ** Arguments for the command.
    char **arguments;
    /// \brief void * Function to call.
    void *(*function)(void *);
} cli_command_t;

void *help_command(void *);
void *info_command(void *);
void *list_command(void *);
void *create_command(void *);
void *use_command(void *);
void *unsubscribe_command(void *);
void *subscribe_command(void *);
void *subscribed_command(void *);
void *messages_command(void *);
void *send_command(void *);
void *user_command(void *);
void *users_command(void *);
void *logout_command(void *);
void *login_command(void *);

/// \brief This function get the commands static const defined in cli_command.c.
/// \return const cli_command_t * An array of available commands.
const cli_command_t *get_cli_commands();

/// \brief This function get a cli_commands depending of it's name.
/// \param char * The called command to find the structure corresponding of the correct structure.
/// \return const cli_command_t * Pointer to the corresponding cli_command.
const cli_command_t *get_cli_command_by_name(char *command);

/// \brief This function get a command, and parse it to fill a structure.
/// \param char *command to be convert in structure.
/// \return A cli_command_t * structure to be used after.
cli_command_t *convert_command_to_structure(char *command);

/// \brief This function call the function store on the structure passed as parameter.
/// \param cli_command_t The structure which contains the function to be call.
/// \return 0, or -1 if an error occurs.
int call_command(cli_command_t *command);

/// \brief This function fill the arguments of the called command in a array of char *.
/// \param char *The command to be parse.
/// \param char *The name of the called command.
/// \return A array of char * which contains all arguments if it's OK, or NULL if an error occurs.
char **fill_command_arguments(char *command, char *name);

#endif /* !PARSER_H_ */
