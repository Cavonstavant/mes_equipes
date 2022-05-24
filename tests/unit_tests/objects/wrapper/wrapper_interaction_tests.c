/*
** EPITECH PROJECT, 2022
** Project
** File description:
** wrapper_interaction_tests
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"
#include "upper_component_adding.h"

Test(objects_my_wrapper, interaction_comment) {
    object_wrapper_t *my_wrapper = wrapper_init();

    bool temp = wrapper_new_comment_to_thread(my_wrapper, (comment_creation_t) {
        "Comments",
        my_uuid_init(USR_),
        my_uuid_init(TEM_)
    }, my_uuid_init(TEM_));

    cr_assert_eq(temp, false);

    wrapper_adding_thread(my_wrapper, (thread_creation_t) {
        "Thread",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    });

    temp = wrapper_new_comment_to_thread(my_wrapper, (comment_creation_t) {
        "Comments",
        my_uuid_init(USR_),
        my_uuid_init(TEM_)
    },  my_wrapper->threads[0]->uuid);

    cr_assert_eq(temp, true);
    cr_assert_eq(my_wrapper->comment_n, 1);
}