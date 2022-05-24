/*
** EPITECH PROJECT, 2022
** Project
** File description:
** wrapper_interaction_tests
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"
#include "upper_component_adding.h"
#include "lower_component_adding.h"

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

Test(objects_my_wrapper, interaction_thread) {
    object_wrapper_t *my_wrapper = wrapper_init();

    bool temp = wrapper_new_thread_to_channel(my_wrapper, (thread_creation_t) {
        "Thread",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    }, my_uuid_init(TEM_));

    cr_assert_eq(temp, false);

    wrapper_adding_channel(my_wrapper, (channel_creation_t) {
        "Chan",
       "Desc",
       my_uuid_init(TEM_)
    });

    temp = wrapper_new_thread_to_channel(my_wrapper, (thread_creation_t) {
        "Thread",
        "Desc",
        my_uuid_init(USR_),
        my_uuid_init(CHA_)
    },  my_wrapper->channels[0]->uuid);

    cr_assert_eq(temp, true);
    cr_assert_eq(my_wrapper->thread_n, 1);
}