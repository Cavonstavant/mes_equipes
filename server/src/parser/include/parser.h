/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** parser
*/

/// \file server/src/parser/include/parser.h

#ifndef PARSER_H_
    #define PARSER_H_

/// \brief Get a command and split it in a array of char *
/// to process the command.
/// \param char * The command to be split.
/// \return char ** The array of char * to be process.
char **split_command(char *command);

#endif /* !PARSER_H_ */
