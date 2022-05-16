/*
** EPITECH PROJECT, 2022
** Project
** File description:
** lower_component_adding_test
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"
#include "lower_component_adding.h"

Test(objects_my_wrapper, add_message) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_message(my_wrapper, (message_creation_t) {
        "My_comment"

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->message_n != 1)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_messages) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_message(my_wrapper, (message_creation_t) {
        "My_comment"

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (wrapper_adding_message(my_wrapper, (message_creation_t) {
        "My_comment"

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->message_n != 2)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_comment) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_comment(my_wrapper, (comment_creation_t) {
        "My_comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->comment_n != 1)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, add_comments) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    if (wrapper_adding_comment(my_wrapper, (comment_creation_t) {
        "My_comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (wrapper_adding_comment(my_wrapper, (comment_creation_t) {
        "My_comment",
        my_uuid_init(TEM_),
        my_uuid_init(USR_)

    }) == COMPONENT_ERROR)
        cr_assert_eq(1, 2);
    if (my_wrapper->comment_n != 2)
        cr_assert_eq(1, 2);
    wrapper_destroy(my_wrapper);
    cr_assert_eq(2, 2);
}