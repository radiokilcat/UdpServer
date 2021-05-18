cmake_minimum_required(VERSION 3.5)

project(raitec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(raitec main.cpp server.h)
target_link_libraries(raitec ${CONAN_LIBS})
