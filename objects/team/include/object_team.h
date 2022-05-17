/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_team
*/

/// \file objects/team/include/object_team.h

#ifndef OBJECT_TEAM_H_
    #define OBJECT_TEAM_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_description.h"
    #include <stdbool.h>

    ///
    /// \brief Error inside a team object
    ///
    #define TEAM_ERROR NULL

    ///
    /// \brief Operation failed probably caused by a malloc
    ///
    #define OPERATION_FAILED false

    ///
    /// \brief Operation succeed
    ///
    #define OPERATION_SUCCESS true

///
/// \brief Team object
///
///
typedef struct team_s {
    /// Uuid of the team
    my_uuid_t *uuid;
    /// Name of the team
    name_t name;
    /// Description of the team
    description_t description;
    /// Uuid list of the attached channels
    my_uuid_t **channels;
    /// Number of attached channels
    int channel_n;
    /// Uuid list of the authorized users
    my_uuid_t **users;
    /// Number of attached user
    int user_n;
} team_t;

///
/// \brief Team creation object
/// Object containing all the information for team creation
///
typedef struct team_creation_s {
    /// Initial name for the team creation
    char *name;
    /// Initial description for the team creation
    char *description;
} team_creation_t;

///
/// \brief Create a new Team object
///
/// \param content Content of the new Team object
/// \return team_t* Newly created Team object
///
team_t *team_init(team_creation_t content);

///
/// \brief Destroy a team object
/// If the team is TEAM_ERROR, do nothing
///
/// \param team Team object to destroy
///
void team_destroy(team_t *team);

///
/// \brief Dump a team object
///
/// \param team Team object to print
///
void team_dump(team_t *team);

///
/// \brief Edit the uuid of a team object
///
/// \param team Team object to edit
/// \param uuid Uuid to change in the team object
///
void team_edit_uuid(team_t *team, char *uuid);

///
/// \brief Edit the name of a team object
///
/// \param team Team object to edit
/// \param name Name to change in the team object
///
void team_edit_name(team_t *team, char *name);

///
/// \brief Edit the description of a team object
///
/// \param team Team object to edit
/// \param description Description to change in the team object
///
void team_edit_description(team_t *team, char *description);

///
/// \brief Add a channel into the channels list of a team object
///
/// \param team Team object
/// \param channel Uuid object to add in the list
/// \return true When operation success
/// \return false When operation failed
///
bool team_add_channel(team_t *team, my_uuid_t *channel);

///
/// \brief Add a user into the users list of a team object
///
/// \param team Team object
/// \param user Uuid object to add in the list
/// \return true When operation success
/// \return false When operation failed
///
bool team_add_user(team_t *team, my_uuid_t *user);

#endif /* !OBJECT_TEAM_H_ */
