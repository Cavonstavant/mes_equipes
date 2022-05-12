/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** parser
*/

/// \file server/src/cli_commands.h

#ifndef PARSER_H_
    #define PARSER_H_

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

/// \brief This function call the function corresponding to the command.
/// \param char ** Array of arguments which will be used to call the function.
/// \return 0, or -1 if an error occurs.
int call_command(char **arguments);

/// \brief This function get the commands static const defined in cli_command.c.
/// \return const cli_command_t * An array of available commands.
const cli_command_t *get_cli_commands();

/// \brief It get a command and an array of separators.
/// It will split the command by using the separators as separator char.
/// It will return an array of char * containing all arguments.
/// \param char * The command to be split.
/// \param char * The separators array.
/// \return char ** An array of arguments.
char **my_str_to_word_array(char *command, char *separators);

#endif /* !PARSER_H_ */
