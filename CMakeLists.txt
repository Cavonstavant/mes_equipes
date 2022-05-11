cmake_minimum_required(VERSION 3.17)
project(myteams LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)

enable_testing()

if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
    set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_compile_options (
    "-std=gnu11" "-Werror" "-Wall" "-Wextra" "-Wpedantic" "-Wshadow" "-Wpointer-arith" "-Wattributes"
)

add_subdirectory(objects)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(tests)

add_custom_target (re
    COMMAND make clean && make
)

add_custom_target (fclean
    COMMAND make clean
    COMMAND rm -f ${PROJECT_NAME}_cli ${PROJECT_NAME}_server ${PROJECT_NAME}_objects
)