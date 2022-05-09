/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_team
*/

/// \file /objects/include/object_team.h

#ifndef OBJECT_TEAM_H_
    #define OBJECT_TEAM_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_description.h"

///
///@brief Team object
///
///
typedef struct team_s {
    uuid_t uuid; /// Uuid of the team
    name_t name; /// Name of the team
    description_t description; /// Description of the team
    uuid_t *channels; /// Uuid list of the attached channels
    uuid_t *users; /// Uuid list of the authorized users
} team_t;

#endif /* !OBJECT_TEAM_H_ */
