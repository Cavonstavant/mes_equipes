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

    cr_assert_not_null(my_comment);
}

Test(objects_my_comment, invalid_body) {
    comment_t *my_comment = comment_init((comment_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });

    cr_assert_null(my_comment);
}

Test(objects_my_comment, destroy_classic) {
    comment_t *my_comment = comment_init((comment_creation_t) {
        "My_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });

    comment_destroy(my_comment);
}