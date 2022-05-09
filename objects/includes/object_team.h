/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_team
*/

/// \file /objects/includes/object_team.h

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

#endif /* !OBJECT_TEAM_H_ */
