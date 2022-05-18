/*
** EPITECH PROJECT, 2022
** Project
** File description:
** upper_component_cmp
*/

#include <criterion/criterion.h>
#include "object_wrapper.h"
#include "upper_component_adding.h"

Test(objects_my_wrapper, cmp_channel) {
    object_wrapper_t *my_wrapper = wrapper_init();

    wrapper_adding_channel(my_wrapper, (channel_creation_t) {
       "Title",
       "Desc",
       my_uuid_init(TEM_)

    });
    cr_assert_null(wrapper_find_channel(my_wrapper, my_uuid_init(TEM_)));
    cr_assert_not_null(wrapper_find_channel(my_wrapper, my_wrapper->channels[0]->uuid));
}