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

    ///
    /// \brief Error inside a team object
    ///
    #define TEAM_ERROR NULL

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
    int n_channel;
    /// Uuid list of the authorized users
    my_uuid_t **users;
    /// Number of attached user
    int n_user;
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

#endif /* !OBJECT_TEAM_H_ */
