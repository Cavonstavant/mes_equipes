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
/// \brief Comment object
///
///
typedef struct comment_s {
    /// Uuid of the comment
    uuid_t uuid;
    /// Uuid of the attached thread
    uuid_t thread;
    /// Uuid of the attached user
    uuid_t author;
    /// Body object of the comment
    body_t body;
    /// Time creation of the comment
    time_t time;
} comment_t;

#endif /* !OBJECT_COMMENT_H_ */
