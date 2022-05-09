/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_channel
*/

/// \file /objects/include/object_channel.h

#ifndef OBJECT_CHANNEL_H_
    #define OBJECT_CHANNEL_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_description.h"

///
///@brief Channel object
///
///
typedef struct channel_s {
    uuid_t uuid; /// Uuid of the channel
    name_t name; /// Name of the channel
    description_t description; /// Description of the channel
    uuid_t team; /// Uuid of the attached team
    uuid_t *threads; /// Uuid list of the attached threads
} channel_t;

#endif /* !OBJECT_CHANNEL_H_ */
