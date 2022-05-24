set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/wrapper)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/wrapper)

set(SRC
    ${SRC_ROOT}/objects_wrapper_tests.c
    ${SRC_ROOT}/upper_component_adding_tests.c
    ${SRC_ROOT}/lower_component_adding_tests.c
    ${SRC_ROOT}/component_dump_tests.c
    ${SRC_ROOT}/upper_component_get_tests.c
    ${SRC_ROOT}/lower_component_get_tests.c
)

create_test(
    TEST_NAME objects_wrapper_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects ${PROJECT_NAME}_uuid_wrapper
)
