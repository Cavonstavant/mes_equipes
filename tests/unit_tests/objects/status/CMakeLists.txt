set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/status)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/status)

set(SRC
    ${SRC_ROOT}/objects_status_tests.c
)

create_test(
    TEST_NAME objects_status_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects
)
