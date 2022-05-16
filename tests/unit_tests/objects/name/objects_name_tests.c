/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_name_tests
*/

#include <criterion/criterion.h>
#include "object_name.h"

Test(objects_name, classic) {
    name_t name = name_init("Michel");

    cr_assert_str_eq(name, "Michel");
}

Test(objects_name, to_long) {
    name_t name = name_init("Michelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");

    cr_assert_null(name);
}

Test(objects_name, empty) {
    name_t name = name_init("");

    cr_assert_str_eq(name, "");
}

Test(objects_name, destroy_classic) {
    name_t name = name_init("");

    cr_assert_str_eq(name, "");
    name_destroy(name);
}

Test(objects_name, destroy_null) {
    name_destroy(NULL);
}