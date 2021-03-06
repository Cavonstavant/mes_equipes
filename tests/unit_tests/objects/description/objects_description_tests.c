/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_description_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "object_description.h"

Test(objects_description, classic) {
    description_t description = description_init("Michel");

    cr_assert_str_eq(description, "Michel");
}

Test(objects_description, dump, .init=cr_redirect_stdout) {
    description_t description = description_init("Michel");

    description_dump(description);
    cr_assert_stdout_eq_str("Description : Michel\n");
}

Test(objects_description, to_long) {
    description_t description = description_init("MichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");

    cr_assert_null(description);
}

Test(objects_description, empty) {
    description_t description = description_init("");

    cr_assert_str_eq(description, "");
}

Test(objects_description, setter) {
    description_t description = description_init("Michel");

    description_edit_content(description, "Mich");
    cr_assert_str_eq(description, "Mich");
}

Test(objects_description, destroy_classic) {
    description_t description = description_init("");

    cr_assert_str_eq(description, "");
    description_destroy(description);
}

Test(objects_description, destroy_null) {
    description_destroy(NULL);
}