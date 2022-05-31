/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** parser
*/

/// \file server/src/core/include/parser.h

#ifndef PARSER_H_
    #define PARSER_H_

/// \brief Compute the command if it's ok.
/// \param char * Command to be call.
/// \param user_list_t * List of all known users.
/// \param server_data_t * All data from the server to be update by the
/// command.
/// \return 0, or -1 if an error occurs.
int compute_command(char *command, user_list_t *, server_data_t *);

#endif /* !PARSER_H_ */
