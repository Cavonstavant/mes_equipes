/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_uuid
*/

/// \file objects/uuid/include/object_uuid.h

#ifndef OBJECT_UUID_H_
    #define OBJECT_UUID_H_

    #include <stddef.h>
    #include <stdbool.h>
    #include "my_uuid.h"

    /// \brief Error in a UUID object probably malloc
    #define UUID_ERROR NULL

    /// \brief The two uuid are the same
    #define MATCHED true

    /// \brief The two uuid are not the same
    #define MISMATCHED false

/// \brief List of prefixes for all the objects types
typedef enum uuid_type_s {
    /// Team UUID prefix
    TEM_,
    /// Channel UUID prefix
    CHA_,
    /// Thread UUID prefix
    THR_,
    /// Comment UUID prefix
    COM_,
    /// User UUID prefix
    USR_,
    /// Conversation UUID prefix
    CON_,
    /// Message UUID prefix
    DMS_
} uuid_type_t;

/// \brief Uuid object equivalent of a string
/// To Refacto with issue #25
typedef struct my_uuid_s {
    /// Uuid wrapper of uuid_t
    w_uuid_t uuid;
} my_uuid_t;

/// \brief Init a My_uuid object
/// Call the uuid library to generate a unique UUID
/// \param uuid_content Store the type of the uuid
/// \return my_uuid_t The newly created uuid object
my_uuid_t *my_uuid_init(uuid_type_t uuid_content);

/// \brief Destroy a My_uuid object
/// If the uuid_to_destroy is UUID_ERROR, do nothing
/// \param uuid_to_destroy Uuid object to destroy
void my_uuid_destroy(my_uuid_t *uuid_to_destroy);

/// \brief Dump a my_uuid object
/// \param uuid My_uuid object to print
void my_uuid_dump(my_uuid_t *uuid);

/// \brief Edit the content of a My uuid object
/// \param uuid My_uuid object to be edited
/// \param content Content to replace in the my_uuid object
/// \return 0 on success, -1 on failure
int my_uuid_edit_content(my_uuid_t *uuid, char *content);

/// \brief Find an uuid object into a uuid object list
/// \param list List of uuid object
/// \param list_n Size of the uuid object list
/// \param to_find Uuid to find in the list
/// \return int Index of the matching uuid in the list
int my_uuid_find(my_uuid_t **list, int list_n, my_uuid_t *to_find);

/// \brief Compare two uuid object
/// \param first First uuid object
/// \param second Second uuid object
/// \return true When the two uuid are the same
/// \return false When the two uuid are not the same
bool my_uuid_cmp(my_uuid_t *first, my_uuid_t *second);

/// \brief Compare a uuid object and a string
/// \param first First uuid object
/// \param second Second uuid object
/// \return true When the two uuid are the same
/// \return false When the two uuid are not the same
bool my_uuid_cmp_not(my_uuid_t *first, char *second);

/// \brief Creare a uuid from a string
/// \param repr String uuid
/// \return my_uuid_t* Newly created uuid
my_uuid_t *my_uuid_from_string(char *repr);

#endif /* !OBJECT_UUID_H_ */
