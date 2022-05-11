set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/body)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/body)

set(SRC
    ${SRC_ROOT}/objects_body_tests.c
)

create_test(
    TEST_NAME objects_body_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects
)
