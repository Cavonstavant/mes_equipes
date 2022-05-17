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

Test(objects_my_user, setter) {
    user_t *user = user_init((user_creation_t) {
        "My_Comment",
        true
    });

    user_edit_uuid(user, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    user_edit_name(user, "Hey");
    user_edit_status(user, false);
    user_add_team(user, my_uuid_init(CHA_));
    user_add_conversation(user, my_uuid_init(USR_));

    cr_assert_eq(user->team_n, 1);
    cr_assert_eq(user->conversation_n, 1);
    cr_assert_str_eq(user->name, "Hey");
    cr_assert_eq(user->status, false);
    cr_assert_str_eq(user->uuid->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
}

Test(objects_my_user, destroy_classic) {
    user_t *my_user = user_init((user_creation_t) {
        "My_Comment",
        false
    });

    user_destroy(my_user);
}