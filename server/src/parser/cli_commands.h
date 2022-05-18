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

/// \brief This function get the commands static const defined in cli_command.c.
/// \return const cli_command_t * An array of available commands.
const cli_command_t *get_cli_commands();

/// \brief This function get a cli_commands depending of it's name.
/// \return const cli_command_t * Pointer to the corresponding cli_command.
const cli_command_t *get_cli_command_by_name(char *command);


cli_command_t *convert_command_to_structure(char *command);
int call_command(cli_command_t *command);
char **fill_command_arguments(char *command, char *name);

#endif /* !PARSER_H_ */
