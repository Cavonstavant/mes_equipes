/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_user
*/

#ifndef OBJECT_USER_H_
    #define OBJECT_USER_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_status.h"

typedef struct user_s {
    uuid_t uuid;
    name_t name;
    status_t status;
    uuid_t *teams;
    uuid_t *conversation;
} user_t;

#endif /* !OBJECT_USER_H_ */
