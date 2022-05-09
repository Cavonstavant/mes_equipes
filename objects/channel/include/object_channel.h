/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_channel
*/

/// \file objects/channel/include/object_channel.h

#ifndef OBJECT_CHANNEL_H_
    #define OBJECT_CHANNEL_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_description.h"

///
/// \brief Channel object
///
///
typedef struct channel_s {
    /// Uuid of the channel
    uuid_t uuid;
    /// Name of the channel
    name_t name;
    /// Description of the channel
    description_t description;
    /// Uuid of the attached team
    uuid_t team;
    /// Uuid list of the attached threads
    uuid_t *threads;
} channel_t;

#endif /* !OBJECT_CHANNEL_H_ */
