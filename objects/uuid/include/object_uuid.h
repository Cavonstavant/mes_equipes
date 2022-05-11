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

    #define UUID_ERROR NULL

///
/// \brief List of prefixes for all the objects types
///
///
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

///
/// \brief Uuid object equivalent of a string
/// To Refacto with issue #25
///
typedef struct my_uuid_s {
    char *uuid;
    uuid_type_t type;
} my_uuid_t;

///
/// \brief Init a My_uuid object
/// Call the Uuid library to generate a unique UUID
///
/// \param uuid_content Store the type of the uuid
/// \return my_uuid_t The newly created uuid object
///
my_uuid_t my_uuid_init(uuid_type_t uuid_content);

#endif /* !OBJECT_UUID_H_ */
