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

Test(objects_my_comment, dump) {
    comment_t *my_comment = comment_init((comment_creation_t) {
        "My_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });

    comment_dump(my_comment); /// USER JOURNEY TEST
}

Test(objects_my_comment, invalid_body) {
    comment_t *my_comment = comment_init((comment_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });

    cr_assert_null(my_comment);
}

Test(objects_my_comment, setter) {
    comment_t *comment = comment_init((comment_creation_t) {
        "My_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });
    char time_display[20];

    comment_edit_uuid(comment, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    comment_edit_parent(comment, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    comment_edit_author(comment, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    comment_edit_body(comment, "A");
    comment_edit_time(comment, "2022-05-17 18:21:14");

    cr_assert_str_eq(comment->uuid->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(comment->thread->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(comment->author->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(comment->body, "A");
    strftime(time_display, 20, "%Y-%m-%d %H-%M-%S", localtime(&comment->time));
    //cr_assert_str_eq(time_display, "2022-05-17 18:21:14");
}

Test(objects_my_comment, destroy_classic) {
    comment_t *my_comment = comment_init((comment_creation_t) {
        "My_Comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)
    });

    comment_destroy(my_comment);
}