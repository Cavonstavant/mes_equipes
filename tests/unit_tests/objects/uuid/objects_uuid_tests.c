/*
** EPITECH PROJECT, 2022
** Project
** File description:
** objects_my_uuid_tests
*/

#include <criterion/criterion.h>
#include "object_uuid.h"

Test(objects_my_uuid, classic) {
    my_uuid_t *my_uuid = my_uuid_init(COM_);

    if (my_uuid == NULL)
        cr_assert_eq(1, 2);
    cr_assert_eq(2, 2);
}

Test(objects_my_uuid, destroy_classic) {
    my_uuid_t *my_uuid = my_uuid_init(COM_);

    my_uuid_destroy(my_uuid);
}