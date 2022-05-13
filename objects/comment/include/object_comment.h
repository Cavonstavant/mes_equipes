/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_comment
*/

/// \file objects/comment/include/object_comment.h

#ifndef OBJECT_COMMENT_H_
    #define OBJECT_COMMENT_H_

    #include "object_uuid.h"
    #include "object_body.h"
    #include <time.h>

    ///
    /// \brief Error inside a comment object
    ///
    #define COMMENT_ERROR NULL

///
/// \brief Comment object
///
///
typedef struct comment_s {
    /// Uuid of the comment
    my_uuid_t *uuid;
    /// Uuid of the attached thread
    my_uuid_t *thread;
    /// Uuid of the attached user
    my_uuid_t *author;
    /// Body object of the comment
    body_t body;
    /// Time creation of the comment
    time_t time;
} comment_t;

///
/// \brief Comment creation object
/// Object containing all the information for a comment creation
///
typedef struct comment_creation_s {
    /// Initial body for the comment creation
    char *body;
    /// parent thread for the comment creation
    my_uuid_t *thread;
    /// author uuid for the comment creation
    my_uuid_t *author;
} comment_creation_t;

///
/// \brief Init a comment object
///
/// \param content content of the comment object
/// \return comment_t* Newly created content object
///
comment_t *comment_init(comment_creation_t content);

///
/// \brief Destroy a comment object
/// If the comment is COMMENT_ERROR, do nothing
///
/// \param comment Comment object to destroy
///
void comment_destroy(comment_t *comment);

#endif /* !OBJECT_COMMENT_H_ */
