FROM conanio/gcc7

LABEL maintainer="Rodrigo Broggi <rodrigo.broggi@amadeus.com>"

# Run as non-root
USER conan
WORKDIR /home/conan

# Copy current directory to the image/container as conan user
COPY --chown=conan:1001 . pocoLibExamples/

RUN mkdir -p /home/conan/.conan/profiles && \
    printf "[settings]\nos=Linux\nos_build=Linux\narch=x86_64\narch_build=x86_64\ncompiler=gcc\ncompiler.version=7\ncompiler.libcxx=libstdc++11\nbuild_type=Release\n[options]\n[build_requires]\n[env]\n" > /home/conan/.conan/profiles/default

# Building Binary
RUN cd /home/conan/pocoLibExamples && \
    pip install conan --upgrade && \
    conan profile update settings.compiler.libcxx=libstdc++11 default && \
    conan install ./ -if ./build --build=missing && \
    cmake -G "Unix Makefiles" ./ -B./build && \
    cd build && \
    make

# Generate RSA key for testing
RUN cd /home/conan/pocoLibExamples/build && \
    openssl genrsa -passout pass:foobar -des3 -out private.pem 2048 && \
    openssl rsa -in private.pem -passin pass:foobar -outform PEM -pubout -out public.pem

# Run some tests
RUN cd /home/conan/pocoLibExamples/build && \
    ./bin/poco_lib hash SHA256 hex "pocoLibExamples"

# Run dec/enc
RUN cd /home/conan/pocoLibExamples/build && \
    ./bin/poco_lib dec ./private.pem "foobar" hex "$(./bin/poco_lib enc ./public.pem hex "pocoLibExample")"

# Run verify/sign
RUN cd /home/conan/pocoLibExamples/build && \
    ./bin/poco_lib verify SHA256 ./public.pem "$(./bin/poco_lib sign SHA256 ./private.pem foobar hex "pocoLibExamples")" hex "pocoLibExamples"
