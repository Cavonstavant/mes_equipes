/*
** EPITECH PROJECT, 2022
** uuid_wrapper
** File description:
** uuid_wrapper
*/

/// \file src/include/my_uuid.h

#ifndef MY_UUID_H
#define MY_UUID_H

    #include <uuid/uuid.h>
    #include <stdio.h>

/// \brief wrapper struct around uuid_t
typedef struct my_uuid_s {
    /// \brief uuid_t instance
    uuid_t uuid;
    /// \brief null terminated string representation of uuid_t
    char repr[40];
} my_uuid_t;

/// \brief null terminated uuid prefixes for the teams subparts
/// \note Each prefix is 4 characters long
extern const char *TEAMS_UUID_PREFIXES[];

/// \brief UUID prefix getter
/// \param prefix_id The prefix index, please use the proper macros in order
/// to access the correct prefix
/// \return The uuid prefix
static inline const char *get_prefix(int prefix_idx)
{
    return TEAMS_UUID_PREFIXES[prefix_idx];
}

typedef enum my_uuid_prefix_e {
    /// \brief Team UUID
    MY_UUID_PREFIX_TEAM,
    /// \brief Channel UUID
    MY_UUID_PREFIX_CHANNEL,
    /// \brief Thread UUID
    MY_UUID_PREFIX_THREAD,
    /// \brief Comment UUID
    MY_UUID_PREFIX_COMMENT,
    /// \brief User UUID
    MY_UUID_PREFIX_USER,
    /// \brief Conversation UUID
    MY_UUID_PREFIX_CONVERSATION,
    /// \brief Direct Message UUID
    MY_UUID_PREFIX_DIRECT_MESSAGE,
    /// \brief Number of uuid prefixes
    MY_UUID_PREFIX_COUNT
} my_uuid_prefix;

/// \brief Generates a new uuid
/// \param out The output uuid
/// \param prefix The prefix to be inserted before the uuid
/// \return 0 on success, -1 on failure
int my_uuid_generate(my_uuid_t *out, my_uuid_prefix prefix);

/// \brief Copy one uuid from another
/// \param dst The destination uuid
/// \param src The source uuid
/// \return 0 on success, -1 on failure
int my_uuid_copy(my_uuid_t *dst, my_uuid_t *src);

static inline void display_uuid(my_uuid_t *uuid, FILE *stream)
{
    fprintf(stream, "%s\n", uuid->repr);
}

static inline int my_uuid_compare(my_uuid_t uu1, my_uuid_t uu2)
{
    return (uuid_compare(uu1.uuid, uu2.uuid));
}

my_uuid_prefix my_uuid_get_prefix(my_uuid_t *uuid);

#endif /* MY_UUID_H */
