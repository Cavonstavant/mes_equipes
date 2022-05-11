/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** parser
*/

/// \file server/src/cli_commands.h

#ifndef PARSER_H_
    #define PARSER_H_

/// \brief structure to store available client command
typedef struct cli_command_s {
    /// \brief char * The name of the command
    char *name;
    /// \brief char ** Arguments for the command
    char **arguments;
    /// \brief void * Function to call
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

/// \brief Get a command and split it in a array of char *
/// to process the command.
/// \param char * The command to be split.
/// \return char ** The array of char * to be process.
char **split_command(char *command);

/// \brief This function check if arguments are valid, depending of the first
/// element on the array.
/// \param char ** Array of arguments which will be check.
/// \return 0 if arguments are not good, 1 otherwise.
int check_arguments(char **arguments);

/// \brief This function get the commands static const defined in cli_command.c
/// \return const cli_command_t * An array of available commands
const cli_command_t *get_cli_commands();

#endif /* !PARSER_H_ */
