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

Test(objects_my_conversation, dump) {
    conversation_t *my_conversation = conversation_init((conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)
    });

    conversation_dump(my_conversation); /// TO REFACTO WITH USER JOURNERY
}

Test(objects_my_conversation, setter) {
    conversation_t *conversation = conversation_init((conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)
    });

    conversation_edit_uuid(conversation, "CON_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    conversation_add_participant(conversation, my_uuid_init(USR_));
    conversation_add_message(conversation, my_uuid_init(DMS_));

    cr_assert_str_eq(conversation->uuid->uuid.repr, "CON_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_eq(conversation->participant_n, 3);
    cr_assert_eq(conversation->message_n, 1);
}

Test(objects_my_conversation, destroy) {
    conversation_t *my_conversation = conversation_init((conversation_creation_t) {
        my_uuid_init(USR_),
        my_uuid_init(USR_)
    });

    conversation_destroy(my_conversation);
    cr_assert_eq(2, 2);
}