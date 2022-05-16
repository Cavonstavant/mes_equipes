/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_body_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "object_body.h"

Test(objects_body, classic) {
    body_t body = body_init("Michel");

    cr_assert_str_eq(body, "Michel");
}

Test(objects_body, dump, .init=cr_redirect_stdout) {
    body_t body = body_init("Michel");

    body_dump(body);
    cr_assert_stdout_eq_str("Body : Michel\n");
}

Test(objects_body, to_long) {
    body_t body = body_init("MichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllMichelllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");

    cr_assert_null(body);
}

Test(objects_body, empty) {
    body_t body = body_init("");

    cr_assert_str_eq(body, "");
}

Test(objects_body, destroy_classic) {
    body_t body = body_init("");

    cr_assert_str_eq(body, "");
    body_destroy(body);
}

Test(objects_body, destroy_null) {
    body_destroy(NULL);
}