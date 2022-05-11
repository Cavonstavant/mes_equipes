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

/// \brief Check arguments of the command
/// \param char ** Arguments of the command with the command at the index 0
/// \return 0, or -1 if it failed.
int check_arguments(char **arguments);

#endif /* !PARSER_H_ */
