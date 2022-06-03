/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** packer_json
*/

/// \file objects/wrapper/src/pack_wrapper/pack_json.h

#ifndef PACKER_JSON_H_
    #define PACKER_JSON_H_

    #include "object_wrapper.h"
    #include <stdio.h>

/// \brief Pack a wrapper into a json file
/// \param wrapper The wrapper to pack
/// \param path The path to the json file
/// \return true if the wrapper has been successfully packed, false otherwise
bool pack_wrapper_to_json(object_wrapper_t *wrapper, char *path);
/// \brief Pack a channel into a json file
/// \param wrapper The wrapper to pack
/// \param file The file to write the channel into
void pack_wrapper_to_json_channel(object_wrapper_t *wrapper, FILE *file);
/// \brief Pack a comment into a json file
/// \param wrapper The wrapper to pack
/// \param file The file to write the comment into
void pack_wrapper_to_json_conversation(object_wrapper_t *wrapper, FILE *file);
/// \brief Pack a message into a json file
/// \param wrapper The wrapper to pack
/// \param file The file to write the message into
void pack_wrapper_to_json_message(object_wrapper_t *wrapper, FILE *file);
/// \brief Pack a team into a json file
/// \param wrapper The wrapper to pack
/// \param file The file to write the team into
void pack_wrapper_to_json_team(object_wrapper_t *wrapper, FILE *file);
/// \brief Pack a thread into a json file
/// \param wrapper The wrapper to pack
/// \param file The file to write the thread into
void pack_wrapper_to_json_user(object_wrapper_t *wrapper, FILE *file);
/// \brief Pack a user into a json file
/// \param wrapper The wrapper to pack
/// \param file The file to write the user into
void pack_wrapper_to_json_thread(object_wrapper_t *wrapper, FILE *file);
/// \brief Pack a user into a json file
/// \param wrapper The wrapper to pack
/// \param file The file to write the user into
void pack_wrapper_to_json_comment(object_wrapper_t *wrapper, FILE *file);

#endif /* !PACKER_JSON_H_ */
