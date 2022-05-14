/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_conversation_tests
*/

#include <criterion/criterion.h>
#include "object_conversation.h"

Test(objects_my_conversation, classic) {
    conversation_t *my_conversation = conversation_init((conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)
    });

    cr_assert_not_null(my_conversation);
}

Test(objects_my_conversation, destroy) {
    conversation_t *my_conversation = conversation_init((conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)
    });

    conversation_destroy(my_conversation);
    cr_assert_eq(2, 2);
}