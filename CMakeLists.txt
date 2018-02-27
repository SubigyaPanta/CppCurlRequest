cmake_minimum_required(VERSION 3.9)
project(HttpRequest)

set(CMAKE_CXX_STANDARD 11)
#find_library(curl)
set(THREADS_PREFER_PTHREAD_FLAG ON) # For threading
find_package(Threads REQUIRED)

add_executable(HttpRequest main.cpp CurlRequest.cpp)
target_link_libraries(HttpRequest curl Threads::Threads)