set(INC_PARSER ${PROJECT_SOURCE_DIR}/server/src/parser/include)
set(SRC_PARSER ${PROJECT_SOURCE_DIR}/server/src/parser)

set(SRC
    ${SRC_PARSER}/cli_commands.c
    ${SRC_PARSER}/cli_commands.h
    ${SRC_PARSER}/compute_command.c
    ${SRC_PARSER}/include/parser.h
)

set(TARGET ${PROJECT_NAME}_parser)

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${INC_PARSER}
    PRIVATE ${SRC_PARSER}
)
