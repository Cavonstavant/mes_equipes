set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/wrapper)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/wrapper)

set(SRC
    ${SRC_ROOT}/objects_wrapper_tests.c
)

create_test(
    TEST_NAME objects_wrapper_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects ${PROJECT_NAME}_uuid_wrapper
)
