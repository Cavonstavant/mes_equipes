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
    /// \brief Error inside a user object
    ///
    #define USER_ERROR NULL

///
/// \brief User object
///
///
typedef struct user_s {
    /// Uuid of the user
    my_uuid_t *uuid;
    /// Name of the user
    name_t name;
    /// Status of the user, isConnected ?
    status_t status;
    /// Uuid list of the attached teams
    my_uuid_t **teams;
    /// Uuid list of the attached conversation
    my_uuid_t **conversation;
} user_t;

///
/// \brief User creation object
/// Object containing all the information for a user creation
///
typedef struct user_creation_s {
    /// Initial name for the user creation
    char *name;
    /// Initial status for the user creation
    bool status;
} user_creation_t;

///
/// \brief Init a new User object
///
/// \param content Content of the new user object
/// \return user_t* Newly created user object
///
user_t *user_init(user_creation_t content);

///
/// \brief Destroy a user object
/// If the user is USER_ERROR, do nothing
///
/// \param user User object to destroy
///
void user_destroy(user_t *user);

#endif /* !OBJECT_USER_H_ */
