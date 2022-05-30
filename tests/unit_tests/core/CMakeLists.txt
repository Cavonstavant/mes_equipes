set(INC_PARSER ${PROJECT_SOURCE_DIR}/tests/unit_tests/core)
set(SRC_PARSER ${PROJECT_SOURCE_DIR}/tests/unit_tests/core)

set(SRC
    ${SRC_PARSER}/compute_command_test.c
)

create_test(
    TEST_NAME server_core_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_server_core
)
