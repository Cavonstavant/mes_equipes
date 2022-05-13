/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_comment_tests
*/

#include <criterion/criterion.h>
#include "object_comment.h"

Test(objects_my_comment, classic) {
    comment_t *my_comment = comment_init((comment_creation_t) {
        "My_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });

    if (my_comment == NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_comment, invalid_body) {
    comment_t *my_comment = comment_init((comment_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });

    if (my_comment != NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_comment, destroy_classic) {
    comment_t *my_comment = comment_init((comment_creation_t) {
        "My_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });

    comment_destroy(my_comment);
}