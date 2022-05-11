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

/// \brief This function check if arguments are valid, depending of the first
/// element on the array.
/// \param char ** Array of arguments which will be check.
/// \return 0 if arguments are not good, 1 otherwise.
int check_arguments(char **arguments);

#endif /* !PARSER_H_ */
