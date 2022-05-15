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

    if (my_team == NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_team, invalid_name) {
    team_t *my_team = team_init((team_creation_t) {
        "My_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_CommentMy_Comment",
        "My_description"
    });

    if (my_team != NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_team, invalid_desc) {
    team_t *my_team = team_init((team_creation_t) {
        "My_Comment",
        "My descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy descriptionMy description"
    });

    if (my_team != NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_team, destroy_classic) {
    team_t *my_team = team_init((team_creation_t) {
        "My_Comment",
        "My description"
    });

    team_destroy(my_team);
}