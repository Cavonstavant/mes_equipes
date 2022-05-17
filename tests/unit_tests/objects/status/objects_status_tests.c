/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_status_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "object_status.h"

Test(objects_status, classic) {
    status_t status = status_init();

    cr_assert_eq(status, OFFLINE);
}

Test(objects_status, dump, .init=cr_redirect_stdout) {
    status_t status = status_init();

    status_dump(status);
    cr_assert_stdout_eq_str("Status : offline\n");
}

Test(objects_status, destroy_status) {
    status_t status = status_init();

    status_destroy(status);
}