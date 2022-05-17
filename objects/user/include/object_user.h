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
    /// \brief Operation failed probably caused by a malloc
    ///
    #define OPERATION_FAILED false

    ///
    /// \brief Operation succeed
    ///
    #define OPERATION_SUCCESS true

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
    /// Number of attached team
    int team_n;
    /// Uuid list of the attached conversation
    my_uuid_t **conversations;
    /// Number of attached conversation
    int conversation_n;
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

///
/// \brief Dump a user object
///
/// \param user User object to print
///
void user_dump(user_t *user);

///
/// \brief Edit the uuid of a user
///
/// \param user Channel object to edit
/// \param uuid Uuid to change in the user object
///
void user_edit_uuid(user_t *user, char *uuid);

///
/// \brief Edit the name of a user
///
/// \param user Channel object to edit
/// \param name Name to change in the user object
///
void user_edit_name(user_t *user, char *name);

///
/// \brief Edit the status of a user
///
/// \param user Channel object to edit
/// \param status Status to change in the user object
///
void user_edit_status(user_t *user, status_t status);

///
/// \brief Add a team into the teams list of a user object
///
/// \param user User object
/// \param team Uuid object to add in the list
/// \return true When operation success
/// \return false When operation failed
///
bool user_add_team(user_t *user, my_uuid_t *team);

///
/// \brief Add a conversation into the conversations list of a user object
///
/// \param user User object
/// \param conversation Uuid object to add in the list
/// \return true When operation success
/// \return false When operation failed
///
bool user_add_conversation(user_t *user, my_uuid_t *conversation);

///
/// \brief Remove a team into the teams list of a user object
///
/// \param user User object
/// \param team Uuid object to remove in the list
/// \return true When operation success
/// \return false When operation failed
///
bool user_remove_team(user_t *user, my_uuid_t *team);

#endif /* !OBJECT_USER_H_ */
