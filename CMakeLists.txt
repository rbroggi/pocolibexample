cmake_minimum_required(VERSION 2.8.12)
project(PocoLibExamples)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(include)
include_directories(src)

add_executable(poco_lib src/main.cpp src/usecase/HexAndBase64Utils.cpp include/HexAndBase64Utils.h src/usecase/Sign.cpp src/usecase/Sign.h src/usecase/Hash.cpp src/usecase/Hash.h src/usecase/Verify.cpp src/usecase/Verify.h src/usecase/Encrypt.cpp src/usecase/Encrypt.h src/usecase/Decrypt.cpp src/usecase/Decrypt.h src/usecase/UsecaseFactory.cpp src/usecase/UsecaseFactory.h src/usecase/UseCase.h src/usecase/Format.cpp src/usecase/Format.h)
target_link_libraries(poco_lib ${CONAN_LIBS})
