
# Poco lib Examples using conan and cmake

### Dependencies
1. [conan](https://conan.io/) - cpp dependency management
2. [cmake](https://cmake.org/) - building tool

### Build
1. checkout repo  
`$ git clone ...`
1. jump into project directory  
`$ cd pocoLibExamples`
1. fetch dependencies using conan (option --build=missing says to conan to compile dependencies in case bin not found). Another useful flag is to set the profile using the `-pr <profile>` flag which points to profiles containing specific compilers in the system.  
    `$ conan install ./ -if ./build --build=missing`  
1. compile  
    i. `$ cmake -G "Unix Makefiles" ./ -B./build`  
    ii. `$ cd build && make`
