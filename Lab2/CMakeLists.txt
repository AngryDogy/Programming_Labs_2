cmake_minimum_required(VERSION 3.20)
project(lab2)
include_directories(curl-7.82.0/include)
link_directories(curl-7.82.0/lib)
set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp Valute.h Request.h)
target_link_libraries(lab2 curl)
