
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
1. Run binary with options:
```bash
poco_lib enc <publicKeyPath> <bin/hex/b64> <content>
poco_lib dec <privKeyPath> <pwd> <bin/hex/b64> <content>
poco_lib sign <MD5/SHA1/SHA256/SHA512> <private_key_file> <pwd> <bin/hex/b64> <content>
poco_lib verify <MD5/SHA1/SHA256/SHA512> <public_key_file_path> <signature> <signFormat:bin/hex/b64> <content>
poco_lib hash <MD5/SHA1/SHA256/SHA512> <bin/hex/b64> <content>
```

The code has an embedded profiler, thanks to [Yan Chernikov](https://github.com/TheCherno) for the profiler [video](https://www.youtube.com/watch?v=xlAH4dbMVnU). To use the profiler, whenever executed in debug mode a file `results.json` will be dumped in the directory of execution. using [chrome](https://www.google.com/chrome/?brand=CHBD&gclid=Cj0KCQiA2b7uBRDsARIsAEE9XpH-d98Bck55bnsLjWP3gl1tF0JF8xjRX8VSXEds4GkZ4B2uyj3g_x0aAmzFEALw_wcB&gclsrc=aw.ds) browser you can navigate to its embedded tracer on the following [address](chrome://tracing/) and load the json file to have a visual representation for the tracer.
