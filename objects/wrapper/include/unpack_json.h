/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** unpack_json
*/

/// \file objects/wrapper/src/unpack_json.h

#ifndef UNPACK_JSON_H_
    #define UNPACK_JSON_H_

    #include "object_wrapper.h"

/// \brief Get a number after a balise on a json file
/// \param file The file to read the number from
/// \param occurance The number of the balise to skip
/// \param balise The balise to find
/// \return The number after the balise
int get_balise_number(char *file, int occurance, char *balise);
/// \brief Get a string after a balise on a json file
/// \param file The file to read the string from
/// \param occurance The number of the balise to skip
/// \param balise The balise to find
/// \return The string after the balise
char *get_balise_content(char *file, int occurance, char *balise);
/// \brief Unpack a json file into a wrapper
/// \param path The path to the json file
/// \return The wrapper created from the json file
object_wrapper_t *unpack_json_to_wrapper(char *path);
/// \brief Unpack channels from a json file into a wrapper
/// \param wrapper The wrapper to fill
/// \param file The file to read the channels from
/// \return true if the channels were successfully unpacked, false otherwise
bool unpack_json_to_wrapper_channel(object_wrapper_t *wrapper, char *file);
/// \brief Unpack team from a json file into a wrapper
/// \param wrapper The wrapper to fill
/// \param file The file to read the team from
/// \return true if the team were successfully unpacked, false otherwise
bool unpack_json_to_wrapper_team(object_wrapper_t *wrapper, char *file);
/// \brief Unpack user from a json file into a wrapper
/// \param wrapper The wrapper to fill
/// \param file The file to read the user from
/// \return true if the user were successfully unpacked, false otherwise
bool unpack_json_to_wrapper_user(object_wrapper_t *wrapper, char *file);
/// \brief Unpack comment from a json file into a wrapper
/// \param wrapper The wrapper to fill
/// \param file The file to read the comment from
/// \return true if the comment were successfully unpacked, false otherwise
bool unpack_json_to_wrapper_comment(object_wrapper_t *wrapper, char *file);
/// \brief Unpack conversation from a json file into a wrapper
/// \param wrapper The wrapper to fill
/// \param file The file to read the conversation from
/// \return true if the conversation were successfully unpacked,
/// false otherwise
bool unpack_json_to_wrapper_conversation(object_wrapper_t *wrapper,
char *file);
/// \brief Unpack message from a json file into a wrapper
/// \param wrapper The wrapper to fill
/// \param file The file to read the message from
/// \return true if the message were successfully unpacked, false otherwise
bool unpack_json_to_wrapper_message(object_wrapper_t *wrapper, char *file);
/// \brief Unpack thread from a json file into a wrapper
/// \param wrapper The wrapper to fill
/// \param file The file to read the thread from
/// \return true if the thread were successfully unpacked, false otherwise
bool unpack_json_to_wrapper_thread(object_wrapper_t *wrapper, char *file);
/// \brief Find string in a file
/// \param file The file to read the string from
/// \param string The string to find
/// \return The index of the string in the file, -1 if the string was not found
int find_str(char *file, char *to_find);
/// \brief Read a file
/// \param fd The file descriptor to read from
/// \return The file content
char *readfile(int fd);

#endif /* !UNPACK_JSON_H_ */
