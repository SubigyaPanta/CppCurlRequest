cmake_minimum_required(VERSION 3.9)
project(HttpRequest)

set(CMAKE_CXX_STANDARD 11)
#find_library(curl)

add_executable(HttpRequest main.cpp )
target_link_libraries(HttpRequest curl)