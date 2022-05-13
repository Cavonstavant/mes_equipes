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

    if (my_user == NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_user, invalid_name) {
    user_t *my_user = user_init((user_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment",
        false
    });

    if (my_user != NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_user, destroy_classic) {
    user_t *my_user = user_init((user_creation_t) {
        "My_Comment",
        false
    });

    user_destroy(my_user);
}