set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/uuid)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/uuid)

set(SRC
    ${SRC_ROOT}/objects_uuid_tests.c
)

create_test(
    TEST_NAME objects_uuid_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects
)
