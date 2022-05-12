/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_threads
*/

/// \file objects/thread/include/object_thread.h

#ifndef OBJECT_THREAD_H_
    #define OBJECT_THREAD_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_body.h"
    #include <time.h>

///
/// \brief Thread object
///
///
typedef struct thread_s {
    /// Uuid of the thread
    my_uuid_t uuid;
    /// Uuid of the attached author
    my_uuid_t author;
    /// Uuid of the attached channel
    my_uuid_t channel;
    /// Name of the thread
    name_t name;
    /// Body of the thread
    body_t body;
    /// Time of creation of the thread
    time_t date;
    /// Uuid list of the attached comments
    my_uuid_t *comments;
} thread_t;

///
/// \brief Thread creation object
/// Object containing all the information for a thread creation
///
typedef struct thread_creation_s {
    /// Initial name for the thread creation
    name_t name;
    /// Initial body for the thread creation
    body_t body;
    /// Author uuid of the thread
    my_uuid_t author;
    /// parent channel for the thread creation
    my_uuid_t channel;
} thread_creation_t;

#endif /* !OBJECT_THREADS_H_ */
