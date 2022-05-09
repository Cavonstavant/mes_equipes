/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_channel
*/

#ifndef OBJECT_CHANNEL_H_
    #define OBJECT_CHANNEL_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_description.h"

typedef struct channel_s {
    uuid_t uuid;
    name_t name;
    description_t description;
    uuid_t team;
    uuid_t *threads;
} channel_t;

#endif /* !OBJECT_CHANNEL_H_ */
