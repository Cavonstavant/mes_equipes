/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_description_tests
*/

#include <criterion/criterion.h>
#include "object_description.h"

Test(objects_description, classic) {
    description_t description = description_init("Michel");

    cr_assert_str_eq(description, "Michel");
}

Test(objects_description, to_long) {
    description_t description = description_init("MichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");

    cr_assert_null(description);
}

Test(objects_description, empty) {
    description_t description = description_init("");

    cr_assert_str_eq(description, "");
}

Test(objects_description, destroy_classic) {
    description_t description = description_init("");

    cr_assert_str_eq(description, "");
    description_destroy(description);
}

Test(objects_description, destroy_null) {
    description_destroy(NULL);
}