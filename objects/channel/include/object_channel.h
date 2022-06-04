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
    #include <stdbool.h>

    /// \brief Error inside a channel object
    #define CHANNEL_ERROR NULL

    /// \brief Operation failed probably caused by a malloc
    #define OPERATION_FAILED false

    /// \brief Operation succeed
    #define OPERATION_SUCCESS true

/// \brief Channel object
typedef struct channel_s {
    /// Uuid of the channel
    my_uuid_t *uuid;
    /// Name of the channel
    name_t name;
    /// Description of the channel
    description_t description;
    /// Uuid of the attached team
    my_uuid_t *team;
    /// Uuid list of the attached threads
    my_uuid_t **threads;
    /// Number of attached threads
    int threads_n;
} channel_t;

/// \brief Channel creation object
/// Object containing all the information for a channel creation
typedef struct channel_creation_s {
    /// Initial team for the channel creation
    char *name;
    /// Initial description for the channel creation
    char *description;
    /// parent team for the channel creation
    my_uuid_t *team;
} channel_creation_t;

/// \brief Init a Channel object
/// \param content Content of the new Channel object
/// \return channel_t* channel_t newly created
channel_t *channel_init(channel_creation_t content);

/// \brief Destroy a channel object
/// If the channel is CHANNEL_ERROR, do nothing
/// \param channel Channel object to destroy
void channel_destroy(channel_t *channel);

/// \brief Dump a channel object
/// \param channel Channel object to print
void channel_dump(channel_t *channel);

/// \brief Edit the uuid of a channel
/// \param channel Channel object to edit
/// \param uuid Uuid to change in the channel object
void channel_edit_uuid(channel_t *channel, char *uuid);

/// \brief Edit the name of a channel
/// \param channel Channel object to edit
/// \param name Name to change in the channel object
void channel_edit_name(channel_t *channel, char *name);

/// \brief Edit the parent of a channel
/// \param channel Channel object to edit
/// \param parent Parent to change in the channel object
void channel_edit_parent(channel_t *channel, char *parent);

/// \brief Add a thread into the threads list of a channel object
/// \param channel Channel object
/// \param thread Uuid object to add in the list
/// \return true When operation success
/// \return false When operation failed
bool channel_add_threads(channel_t *channel, my_uuid_t *thread);

#endif /* !OBJECT_CHANNEL_H_ */
