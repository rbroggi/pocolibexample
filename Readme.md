
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
`$ conan install ./ -if=./cmake-build-debug -pr=clang`  
`$ conan install ./ -if <install_folder> -pr <profile>`
1. compile  
`$ cmake  -G "Unix Makefiles" ./`
