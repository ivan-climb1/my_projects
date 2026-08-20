cmake_minimum_required(VERSION 3.10)

set(project_name observer)

project(${project_name})

file(GLOB_RECURSE source_files CONFIGURE_DEPENDS "source/*.cpp")
file(GLOB_RECURSE header_files CONFIGURE_DEPENDS "include/*.h")

add_executable(${project_name} ${source_files} ${header_files})

target_include_directories(${project_name} PRIVATE "include")
target_include_directories(${project_name} PRIVATE "include/interface")

target_compile_options(${project_name} PRIVATE -Wall -Wextra -Werror -pedantic -std=c++17)