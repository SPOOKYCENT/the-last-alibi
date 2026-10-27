
cmake_minimum_required(VERSION 3.16)

project(TheLastAlibi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(the_last_alibi
    
)

target_include_directories(the_last_alibi PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_compile_options(the_last_alibi PRIVATE
    -Wall
    -Wextra
)
