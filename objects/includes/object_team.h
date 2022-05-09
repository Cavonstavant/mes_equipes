/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_team
*/

#ifndef OBJECT_TEAM_H_
    #define OBJECT_TEAM_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_description.h"

typedef struct team_s {
    uuid_t uuid;
    name_t name;
    description_t description;
    uuid_t *channels;
    uuid_t *users;
} team_t;

#endif /* !OBJECT_TEAM_H_ */
