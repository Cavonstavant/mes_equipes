/*
** EPITECH PROJECT, 2022
** Project
** File description:
** lower_component_cmp
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"
#include "lower_component_adding.h"

Test(objects_my_wrapper, cmp_message) {
    object_wrapper_t *my_wrapper = wrapper_init();

    wrapper_adding_message(my_wrapper, (message_creation_t) {
       "Title"

    });
    cr_assert_null(wrapper_find_message(my_wrapper, my_uuid_init(TEM_)));
    cr_assert_not_null(wrapper_find_message(my_wrapper, my_wrapper->messages[0]->uuid));
}

Test(objects_my_wrapper, cmp_comment) {
    object_wrapper_t *my_wrapper = wrapper_init();

    wrapper_adding_comment(my_wrapper, (comment_creation_t) {
       "Title",
       my_uuid_init(TEM_),
       my_uuid_init(USR_)

    });
    cr_assert_null(wrapper_find_comment(my_wrapper, my_uuid_init(TEM_)));
    cr_assert_not_null(wrapper_find_comment(my_wrapper, my_wrapper->comments[0]->uuid));
}