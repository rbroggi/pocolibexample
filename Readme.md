
# Poco lib Examples using conan and cmake

### Dependencies
1. [conan](https://conan.io/) - cpp dependency management
2. [cmake](https://cmake.org/) - building tool

### Build
1. checkout repo  
`$ git clone ...`
1. jump into project directory  
`$ cd pocoLibExamples`
1. fetch dependencies using conan (and CLion which uses clang - assuming a conan clang profile exists in `~/.conan/profiles/clang`)  
    i. (clang) `$ conan install ./ -if=./build -pr=clang --build zlib --build OpenSSL --build Poco`  
    ii. (gnu) `$ conan install ./ -if ./build `
1. compile  
    i. `$ cmake -G "Unix Makefiles" ./ -B./build`  
    ii. `$ cd build && make`
