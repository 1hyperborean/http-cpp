cmake_minimum_required(VERSION 3.30)
project(webserver)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_OSX_ARCHITECTURES "arm64")

add_executable(webserver main.cpp)
