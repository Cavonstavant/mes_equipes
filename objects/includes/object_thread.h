/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_threads
*/

/// \file /objects/include/object_thread.h

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
    uuid_t uuid;
    /// Uuid of the attached author
    uuid_t author;
    /// Uuid of the attached channel
    uuid_t channel;
    /// Name of the thread
    name_t name;
    /// Body of the thread
    body_t body;
    /// Time of creation of the thread
    time_t date;
    /// Uuid list of the attached comments
    uuid_t *comments;
} thread_t;

#endif /* !OBJECT_THREADS_H_ */
