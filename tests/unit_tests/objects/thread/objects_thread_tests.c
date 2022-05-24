/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_thread_tests
*/

#include <criterion/criterion.h>
#include "object_thread.h"

Test(objects_my_thread, classic) {
    thread_t *my_thread = thread_init((thread_creation_t) {
        "My_Comment",
        "My description",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });

    cr_assert_not_null(my_thread);
}

Test(objects_my_thread, dump) {
    thread_t *my_thread = thread_init((thread_creation_t) {
        "My_Thread",
        "My description",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });

    thread_dump(my_thread); /// TO REFACTO WITH USER JOURNEY
}

Test(objects_my_thread, invalid_name) {
    thread_t *my_thread = thread_init((thread_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment",
        "My_description",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });

    cr_assert_null(my_thread);
}

Test(objects_my_thread, invalid_desc) {
    thread_t *my_thread = thread_init((thread_creation_t) {
        "My_Comment",
        "My descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy description",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });

    cr_assert_null(my_thread);
}

Test(objects_my_thread, setter) {
    thread_t *thread = thread_init((thread_creation_t) {
        "My_Comment",
        "My description",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });
    char time_display[20];

    thread_edit_uuid(thread, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    thread_edit_author(thread, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    thread_edit_parent(thread, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    thread_edit_name(thread, "H");
    thread_edit_body(thread, "HA");
    thread_add_comment(thread, my_uuid_init(CHA_));
    thread_edit_time(thread, "2022-05-17 18:21:14");

    cr_assert_eq(thread->comment_n, 1);
    cr_assert_str_eq(thread->author->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(thread->channel->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(thread->uuid->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(thread->name, "H");
    cr_assert_str_eq(thread->body, "HA");
    strftime(time_display, 20, "%Y-%m-%d %H:%M:%S", localtime(&thread->date));
    //cr_assert_str_eq(time_display, "2022-05-17 18:21:14");
}

Test(objects_my_thread, destroy_classic) {
    thread_t *my_thread = thread_init((thread_creation_t) {
        "My_Comment",
        "My description",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });

    thread_destroy(my_thread);
}