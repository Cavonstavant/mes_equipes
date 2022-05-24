/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_name_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "object_name.h"

Test(objects_name, classic) {
    name_t name = name_init("Michel");

    cr_assert_str_eq(name, "Michel");
}

Test(objects_name, dump, .init=cr_redirect_stdout) {
    name_t name = name_init("Michel");

    name_dump(name);
    cr_assert_stdout_eq_str("Name : Michel\n");
}

Test(objects_name, to_long) {
    name_t name = name_init("Michelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");

    cr_assert_null(name);
}

Test(objects_name, empty) {
    name_t name = name_init("");

    cr_assert_str_eq(name, "");
}

Test(objects_name, setter) {
    name_t name = name_init("Michel");

    name_edit_content(name, "Mich");
    cr_assert_str_eq(name, "Mich");
}

Test(objects_name, destroy_classic) {
    name_t name = name_init("");

    cr_assert_str_eq(name, "");
    name_destroy(name);
}

Test(objects_name, destroy_null) {
    name_destroy(NULL);
}