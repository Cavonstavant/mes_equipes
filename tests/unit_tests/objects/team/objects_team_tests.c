/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_team_tests
*/

#include <criterion/criterion.h>
#include "object_team.h"

Test(objects_my_team, classic) {
    team_t *my_team = team_init((team_creation_t) {
        "My_Comment",
        "My description"
    });

    cr_assert_not_null(my_team);
}

Test(objects_my_team, dump) {
    team_t *my_team = team_init((team_creation_t) {
        "My_Team",
        "My description"
    });

    team_dump(my_team); /// TO REFACTO WITH USER JOURNEY
}

Test(objects_my_team, invalid_name) {
    team_t *my_team = team_init((team_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment",
        "My_description"
    });

    cr_assert_null(my_team);
}

Test(objects_my_team, invalid_desc) {
    team_t *my_team = team_init((team_creation_t) {
        "My_Comment",
        "My descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy description"
    });

    cr_assert_null(my_team);
}

Test(objects_my_team, setter) {
    team_t *team = team_init((team_creation_t) {
        "My_Comment",
        "My description"
    });

    team_edit_uuid(team, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    team_edit_name(team, "Hey");
    team_edit_description(team, "H");
    team_add_channel(team, my_uuid_init(CHA_));
    team_add_user(team, my_uuid_init(USR_));

    cr_assert_eq(team->channel_n, 1);
    cr_assert_eq(team->user_n, 1);
    cr_assert_str_eq(team->name, "Hey");
    cr_assert_str_eq(team->description, "H");
    cr_assert_str_eq(team->uuid->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
}

Test(objects_my_team, destroy_classic) {
    team_t *my_team = team_init((team_creation_t) {
        "My_Comment",
        "My description"
    });

    team_destroy(my_team);
}