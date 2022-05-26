set (INCLUDE_DIR ${PROJECT_SOURCE_DIR}/client/src/include)
set (SRC_DIR ${PROJECT_SOURCE_DIR}/client/src)

set (TARGET ${PROJECT_NAME}_cli)


set (SRC
    ${SRC_DIR}/entrypoint.c
)

add_executable(${TARGET} ${SRC})

# target_include_directories(${TARGET}_core
#     PUBLIC ${INCLUDE_DIR}
#     PRIVATE ${SRC_DIR}
# )

target_link_directories(${TARGET}
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
)

target_link_libraries(${TARGET} 
    PUBLIC myteams
)

target_include_directories(${TARGET}
    PUBLIC ${PROJECT_SOURCE_DIR}/libs
)

set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)
