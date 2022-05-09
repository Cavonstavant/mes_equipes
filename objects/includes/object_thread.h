/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_threads
*/

#ifndef OBJECT_THREAD_H_
    #define OBJECT_THREAD_H_

    #include "object_uuid.h"
    #include "object_name.h"
    #include "object_body.h"
    #include <time.h>

typedef struct thread_s {
    uuid_t uuid;
    uuid_t author;
    uuid_t channel;
    name_t name;
    body_t body;
    time_t date;
    uuid_t *comments;
} thread_t;

#endif /* !OBJECT_THREADS_H_ */
