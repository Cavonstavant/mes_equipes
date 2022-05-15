set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/name)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/name)

set(SRC
    ${SRC_ROOT}/objects_name_tests.c
)

create_test(
    TEST_NAME objects_name_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects
)
