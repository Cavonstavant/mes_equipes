set(INCLUDE_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/<ModuleName>)
set(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests/unit_tests/<ModuleName>)

set(SRC
    ${SRC_ROOT}/<ModuleName>_test.c
)

create_test(
    TEST_NAME <ModuleName>_tests
    TEST_SRC ${SRC}
    TEST_DEPS <Module Dependencies>
)
