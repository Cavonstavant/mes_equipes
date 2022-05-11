/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** parser
*/

/// \file server/src/include/parser.h

#ifndef PARSER_H_
    #define PARSER_H_

/// \brief This function check if arguments are valid, depending of the first
/// element on the array.
/// \param char ** Array of arguments which will be check.
/// \return 0 if arguments are not good, 1 otherwise.
int check_arguments(char **arguments);

#endif /* !PARSER_H_ */
