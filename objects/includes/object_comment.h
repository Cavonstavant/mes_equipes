/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_comment
*/

#ifndef OBJECT_COMMENT_H_
    #define OBJECT_COMMENT_H_

    #include "object_uuid.h"
    #include "object_body.h"
    #include <time.h>

typedef struct comment_s {
    uuid_t uuid;
    uuid_t thread;
    uuid_t author;
    body_t body;
    time_t time;
} comment_t;

#endif /* !OBJECT_COMMENT_H_ */
