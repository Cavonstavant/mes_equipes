/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_user
*/

/// \file /objects/include/object_user.h

#ifndef OBJECT_USER_H_
    #define OBJECT_USER_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_status.h"

///
///@brief User object
///
///
typedef struct user_s {
    uuid_t uuid; /// Uuid of the user
    name_t name; /// Name of the user
    status_t status; /// Status of the user, isConnected ?
    uuid_t *teams; /// Uuid list of the attached teams
    uuid_t *conversation; /// UUid list of the attached conversation
} user_t;

#endif /* !OBJECT_USER_H_ */
