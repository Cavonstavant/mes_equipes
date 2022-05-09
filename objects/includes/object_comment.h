/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_comment
*/

/// \file /objects/include/object_comment.h

#ifndef OBJECT_COMMENT_H_
    #define OBJECT_COMMENT_H_

    #include "object_uuid.h"
    #include "object_body.h"
    #include <time.h>

///
///@brief Comment object
///
///
typedef struct comment_s {
    uuid_t uuid; /// Uuid of the comment
    uuid_t thread; /// Uuid of the attached thread
    uuid_t author; /// Uuid of the attached user
    body_t body; /// Body object of the comment
    time_t time; /// Time creation of the comment 
} comment_t;

#endif /* !OBJECT_COMMENT_H_ */
