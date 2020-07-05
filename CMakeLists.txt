cmake_minimum_required(VERSION 3.14)

project(c-hash)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(include)

set(SOURCES
    src/chained-hash-table.c
)

add_library(chash STATIC ${SOURCES})
add_library(chash-string src/string-concrete-hash-function.c)

add_executable(example1 example/example1.c)
target_link_libraries(example1 chash chash-string m)


