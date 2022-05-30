set (INC_COMMANDS ${PROJECT_SOURCE_DIR}/server/src/commands)
set (SRC_COMMANDS ${PROJECT_SOURCE_DIR}/server/src/commands)

set (TARGET ${PROJECT_NAME}_commands)

set (SRC
    ${SRC_COMMANDS}/command_send.c
    ${INC_COMMANDS}/rcodes.h
)

add_library(${TARGET} ${SRC})

target_include_directories(${TARGET}
    PUBLIC ${INC_COMMANDS}
    PRIVATE ${SRC_COMMANDS}
)

set_target_properties(${TARGET}
    PROPERTIES
    LINKER_LANGUAGE  C
)
