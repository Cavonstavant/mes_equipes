set (INC_ROOT ${PROJECT_SOURCE_DIR}/server/src)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/server/src)

set (TARGET ${PROJECT_NAME}_server)

set (SRC
    ${SRC_ROOT}/entrypoint.c
)

add_executable(${TARGET} ${SRC})

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

target_include_directories(${TARGET}
    PUBLIC ${INC_ROOT}
    PRIVATE ${SRC_ROOT}
)

target_link_libraries(${TARGET}
    PUBLIC ${TARGET}_core
)

add_subdirectory(core)
