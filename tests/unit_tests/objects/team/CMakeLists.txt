set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/team)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/objects/team)

set(SRC
    ${SRC_ROOT}/objects_team_tests.c
)

create_test(
    TEST_NAME objects_team_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_objects ${PROJECT_NAME}_uuid_wrapper
)
