cmake_minimum_required(VERSION 3.0)

project(work_with_pipe)

add_executable(server source/server.cpp source/pipe_work.cpp)
add_executable(client source/client.cpp source/pipe_work.cpp)

target_include_directories(server PRIVATE include/)
target_include_directories(client PRIVATE include/)

target_compile_options(server PRIVATE -Wall -Wextra -Werror -pedantic -std=c++17)
target_compile_options(client PRIVATE -Wall -Wextra -Werror -pedantic -std=c++17)

target_link_libraries(server stdc++fs)
target_link_libraries(client stdc++fs)
