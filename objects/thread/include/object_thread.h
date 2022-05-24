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
    #include <stdbool.h>

    ///
    /// \brief Error inside a thread object
    ///
    #define THREAD_ERROR NULL

    ///
    /// \brief Operation failed probably caused by a malloc
    ///
    #define OPERATION_FAILED false

    ///
    /// \brief Operation succeed
    ///
    #define OPERATION_SUCCESS true

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
    int comment_n;
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

///
/// \brief Edit the uuid of a thread object
///
/// \param thread Thread object to edit
/// \param uuid Uuid to change in the thread object
///
static inline void thread_edit_uuid(thread_t *thread, char *uuid)
{
    my_uuid_edit_content(thread->uuid, uuid);
}

///
/// \brief Edit the parent of a thread object
///
/// \param thread Thread object to edit
/// \param parent Parent to change in the thread object
///
static inline void thread_edit_parent(thread_t *thread, char *parent)
{
    my_uuid_edit_content(thread->channel, parent);
}

///
/// \brief Edit the author of a thread object
///
/// \param thread Thread object to edit
/// \param author Author to change in the thread object
///
static inline void thread_edit_author(thread_t *thread, char *author)
{
    my_uuid_edit_content(thread->author, author);
}

///
/// \brief Edit the name of a thread object
///
/// \param thread Thread object to edit
/// \param name Name to change in the thread object
///
void thread_edit_name(thread_t *thread, char *name);

///
/// \brief Edit the body of a thread object
///
/// \param thread Thread object to edit
/// \param body Body to change in the thread object
///
void thread_edit_body(thread_t *thread, char *body);

///
/// \brief Edit the time of a thread object
///
/// \param thread Thread object to edit
/// \param time Time to change in the thread object
///
void thread_edit_time(thread_t *thread, char *time);

///
/// \brief Add a comment to the comments list of a thread object
///
/// \param thread Thread object
/// \param comment Uuid object to add in the list
/// \return true When operation success
/// \return false When operation failed
///
bool thread_add_comment(thread_t *thread, my_uuid_t *comment);

#endif /* !OBJECT_THREADS_H_ */
