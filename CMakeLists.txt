cmake_minimum_required(VERSION 2.8.12)
project(PocoLibExamples)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(poco_lib main.cpp)
target_link_libraries(poco_lib ${CONAN_LIBS})
