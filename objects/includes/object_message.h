/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_message
*/

#ifndef OBJECT_MESSAGE_H_
    #define OBJECT_MESSAGE_H_

    #include "object_uuid.h"
    #include "object_body.h"
    #include <time.h>

typedef struct message_s {
    uuid_t uuid;
    body_t body;
    time_t time;
} message_t;

#endif /* !OBJECT_MESSAGE_H_ */
