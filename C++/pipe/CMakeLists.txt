cmake_minimum_required(VERSION 3.0)

#project(work_with_pipe)

include_directories("include/")

add_executable(client source/client.cpp source/pipe_work.cpp)
add_executable(server source/server.cpp source/pipe_work.cpp)

target_link_libraries(client stdc++fs)
target_link_libraries(server stdc++fs)

