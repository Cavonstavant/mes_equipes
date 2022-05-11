/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** split_command
*/

/// \file server/src/parser/split_command.h

#ifndef SPLIT_COMMAND_H_
    #define SPLIT_COMMAND_H_

/// \brief It get a command and an array of separators.
/// It will split the command by using the separators as separator char.
/// It will return an array of char * containing all arguments.
/// \param char * The command to be split.
/// \param char * The separators array.
/// \return char ** An array of arguments.
char **my_str_to_word_array(char *command, char *separators);

#endif /* !SPLIT_COMMAND_H_ */
