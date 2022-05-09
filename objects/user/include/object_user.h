/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_user
*/

/// \file objects/user/include/object_user.h

#ifndef OBJECT_USER_H_
    #define OBJECT_USER_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_status.h"

///
/// \brief User object
///
///
typedef struct user_s {
    /// Uuid of the user
    uuid_t uuid;
    /// Name of the user
    name_t name;
    /// Status of the user, isConnected ?
    status_t status;
    /// Uuid list of the attached teams
    uuid_t *teams;
    /// Uuid list of the attached conversation
    uuid_t *conversation;
} user_t;

///
/// \brief User creation object
/// Object containing all the information for a user creation
///
typedef struct user_creation_s {
    /// Initial name for the user creation
    name_t name;
    /// Initial status for the user creation
    status_t status;
} user_creation_t;

#endif /* !OBJECT_USER_H_ */
