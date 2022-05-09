/*
** EPITECH PROJECT, 2022
** Project
** File description:
** object_conversation
*/

#ifndef OBJECT_CONVERSATION_H_
    #define OBJECT_CONVERSATION_H_

    #include "object_uuid.h"

typedef struct conversation_s {
    uuid_t uuid;
    uuid_t *users;
    uuid_t *message;
} conversation_t;

#endif /* !OBJECT_CONVERSATION_H_ */
