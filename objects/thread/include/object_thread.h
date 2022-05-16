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
    /// \brief Error inside a thread object
    ///
    #define THREAD_ERROR NULL

///
/// \brief Thread object
///
///
typedef struct thread_s {
    /// Uuid of the thread
    my_uuid_t *uuid;
    /// Uuid of the attached author
    my_uuid_t *author;
    /// Uuid of the attached channel
    my_uuid_t *channel;
    /// Name of the thread
    name_t name;
    /// Body of the thread
    body_t body;
    /// Time of creation of the thread
    time_t date;
    /// Uuid list of the attached comments
    my_uuid_t **comments;
    /// Number of attached comment
    int n_comment;
} thread_t;

///
/// \brief Thread creation object
/// Object containing all the information for a thread creation
///
typedef struct thread_creation_s {
    /// Initial name for the thread creation
    char *name;
    /// Initial body for the thread creation
    char *body;
    /// Author uuid of the thread
    my_uuid_t *author;
    /// parent channel for the thread creation
    my_uuid_t *channel;
} thread_creation_t;

///
/// \brief Init a new thread object
///
/// \param content Content of the new thread object
/// \return thread_t* Newly created thread object
///
thread_t *thread_init(thread_creation_t content);

///
/// \brief Destroy a thread object
/// If the thread is THREAD_ERROR, do nothing
///
/// \param thread Thread object to destroy
///
void thread_destroy(thread_t *thread);

///
/// \brief Dump a thread object
///
/// \param thread Thread object to print
///
void thread_dump(thread_t *thread);

#endif /* !OBJECT_THREADS_H_ */
