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
/// \brief Team object
///
///
typedef struct team_s {
    /// Uuid of the team
    uuid_t uuid;
    /// Name of the team
    name_t name;
    /// Description of the team
    description_t description;
    /// Uuid list of the attached channels
    uuid_t *channels;
    /// Uuid list of the authorized users
    uuid_t *users;
} team_t;

///
/// \brief Team creation object
/// Object containing all the information for team creation
///
typedef struct team_creation_s {
    /// Initial name for the team creation
    name_t name;
    /// Initial description for the team creation
    description_t description;
} team_creation_t;

#endif /* !OBJECT_TEAM_H_ */
