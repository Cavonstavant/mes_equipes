set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/description)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/description)

set(SRC
    ${SRC_ROOT}/objects_description_tests.c
)

create_test(
    TEST_NAME objects_description_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects
)
