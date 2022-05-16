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

    cr_assert_not_null(my_uuid);
}

Test(objects_my_uuid, dump) {
    my_uuid_t *my_uuid = my_uuid_init(COM_);

    my_uuid_dump(my_uuid); /// CAN'T predict UUID TO REFACTO WITH SETTER
}

Test(objects_my_uuid, destroy_classic) {
    my_uuid_t *my_uuid = my_uuid_init(COM_);

    my_uuid_destroy(my_uuid);
}