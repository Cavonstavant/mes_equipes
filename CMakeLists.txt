cmake_minimum_required(VERSION 3.17)
project(myteams LANGUAGES C)

set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED true)

add_compile_options(
    "-std=gnu11" "-Wall" "-Wextra" "-Wpedantic" "-Wshadow" "-Wpointer-arith" "-Wattributes"
)

add_subdirectory(objects)
add_subdirectory(client)
add_subdirectory(server)

add_custom_target(re
    COMMAND make clean && make
)

add_custom_target(fclean
    COMMAND make clean
    COMMAND rm -f ${PROJECT_NAME}_cli ${PROJECT_NAME}_server ${PROJECT_NAME}_objects
)