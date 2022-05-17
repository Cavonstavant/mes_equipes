/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_user_tests
*/

#include <criterion/criterion.h>
#include "object_user.h"

Test(objects_my_user, classic) {
    user_t *my_user = user_init((user_creation_t) {
        "My_Comment",
        true
    });

    cr_assert_not_null(my_user);
}

Test(objects_my_user, dump) {
    user_t *my_user = user_init((user_creation_t) {
        "Michel",
        true
    });

    user_dump(my_user); /// TO REFACTO WITH USER JOURNEY
}

Test(objects_my_user, invalid_name) {
    user_t *my_user = user_init((user_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment",
        false
    });

    cr_assert_null(my_user);
}

Test(objects_my_user, destroy_classic) {
    user_t *my_user = user_init((user_creation_t) {
        "My_Comment",
        false
    });

    user_destroy(my_user);
}