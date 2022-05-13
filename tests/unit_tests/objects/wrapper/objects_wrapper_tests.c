/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_wrapper_tests
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"

Test(objects_my_wrapper, classic) {
    object_wrapper_t *my_wrapper = wrapper_init();

    if (my_wrapper == NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_wrapper, destroy_classic) {
    object_wrapper_t *my_wrapper = wrapper_init();

    wrapper_destroy(my_wrapper);
}