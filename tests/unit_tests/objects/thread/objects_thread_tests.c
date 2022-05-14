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

Test(objects_my_thread, destroy_classic) {
    thread_t *my_thread = thread_init((thread_creation_t) {
        "My_Comment",
        "My description",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });

    thread_destroy(my_thread);
}