set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/user)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/user)

set(SRC
    ${SRC_ROOT}/objects_user_tests.c
)

create_test(
    TEST_NAME objects_user_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects ${PROJECT_NAME}_uuid_wrapper
)
