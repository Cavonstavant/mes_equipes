/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_message_tests
*/

#include <criterion/criterion.h>
#include "object_message.h"

Test(objects_my_message, classic) {
    message_t *my_message = message_init((message_creation_t) {
        "My_Comment"
    });

    cr_assert_not_null(my_message);
}

Test(objects_my_message, dump) {
    message_t *my_message = message_init((message_creation_t) {
        "My_message"
    });

    message_dump(my_message); /// TO REFACTO WITH USER JOURNEY
}

Test(objects_my_message, invalid_body) {
    message_t *my_message = message_init((message_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment"
    });

    cr_assert_null(my_message);
}

Test(objects_my_message, setter) {
    message_t *message = message_init((message_creation_t) {
        "My_Comment"
    });
    char time_display[20];

    message_edit_uuid(message, "CON_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    message_edit_body(message, "Hey");
    message_edit_time(message, "2022-05-17 18:21:14");

    cr_assert_str_eq(message->uuid->uuid.repr, "CON_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(message->body, "Hey");
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&message->time));
    //cr_assert_str_eq(time_display, "2022-05-17 18:21:14");
}

Test(objects_my_message, destroy_classic) {
    message_t *my_message = message_init((message_creation_t) {
        "My_Comment"
    });

    message_destroy(my_message);
}