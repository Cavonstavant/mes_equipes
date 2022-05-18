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

Test(objects_my_uuid, setter) {
    my_uuid_t *my_uuid = my_uuid_init(COM_);

    my_uuid_edit_content(my_uuid, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    cr_assert_str_eq(my_uuid->uuid.repr, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
}

Test(objects_my_uuid, find) {
    my_uuid_t *uuid = my_uuid_init(COM_);

    my_uuid_edit_content(uuid, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    my_uuid_t *my_uuid[] = {
        my_uuid_init(COM_),
        uuid
    };

    cr_assert_eq(my_uuid_find(my_uuid, 2, uuid), 1);
}

Test(objects_my_uuid, find_error) {
    my_uuid_t *uuid = my_uuid_init(COM_);

    my_uuid_edit_content(uuid, "USR_df2b5c45-c44b-4c93-8dfb-5c9c36640673");
    my_uuid_t *my_uuid[] = {
        my_uuid_init(COM_),
        my_uuid_init(COM_)
    };

    cr_assert_eq(my_uuid_find(my_uuid, 2, uuid), -1);
}

Test(objects_my_uuid, destroy_classic) {
    my_uuid_t *my_uuid = my_uuid_init(COM_);

    my_uuid_destroy(my_uuid);
}