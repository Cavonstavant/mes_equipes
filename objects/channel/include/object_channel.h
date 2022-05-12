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
    my_uuid_t uuid;
    /// Name of the channel
    name_t name;
    /// Description of the channel
    description_t description;
    /// Uuid of the attached team
    my_uuid_t team;
    /// Uuid list of the attached threads
    my_uuid_t *threads;
} channel_t;

///
/// \brief Channel creation object
/// Object containing all the information for a channel creation
///
typedef struct channel_creation_s {
    /// Initial team for the channel creation
    name_t name;
    /// Initial description for the channel creation
    description_t description;
    /// parent team for the channel creation
    my_uuid_t team;
} channel_creation_t;

#endif /* !OBJECT_CHANNEL_H_ */