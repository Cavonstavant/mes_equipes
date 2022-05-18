set(INC_PARSER ${PROJECT_SOURCE_DIR}/tests/unit_tests/parser)
set(SRC_PARSER ${PROJECT_SOURCE_DIR}/tests/unit_tests/parser)

set(SRC
    ${SRC_PARSER}/compute_command_test.c
)

create_test(
    TEST_NAME parser_tests
    TEST_SRC ${SRC}
    TEST_DEPS ${PROJECT_NAME}_parser
)
