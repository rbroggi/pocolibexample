#include <HexAndBase64Utils.h>
#include <Poco/Crypto/RSADigestEngine.h>
#include <Poco/DigestStream.h>
#include <Poco/MD5Engine.h>
#include <iostream>
#include <profiler/Timer.h>
#include <usecase/UsecaseFactory.h>

namespace crypto = Poco::Crypto;

// Options:
// hash (hash conent using one hashing method)
// arg1: method: "MD5", "SHA1", "SHA256", "SHA512"
// arg2: output format: bin, hex, b64
// arg2: content
// e.g.: poco_lib hash <MD5/SHA1/SHA265/SHA512> <bin/hex/b64> <content>

// enc (encrypt content using RSA public key)
// arg1: publicKey file
// arg2: output format: bin, hex, b64
// arg3: content
// e.g.: poco_lib enc <publicKeyPath> <content>

// dec (decrypt content using RSA private key)
// arg1: private_key_file file
// arg2: pwd
// arg3: input format: bin, hex, b64
// arg4: content
// e.g.: poco_lib dec <privKeyPath> <pwd> <bin/hex/b64> <content>

// sign (sign content using hash method, private key)
// arg1: method: "MD5", "SHA1", "SHA256", "SHA512"
// arg2: private key file path
// arg3: pwd
// arg4: output format: bin, hex, b64
// arg4: content
// e.g.: poco_lib sign <MD5/SHA1/SHA265/SHA512> <private_key_file> <pwd> <bin/hex/b64> <content>

// verify (verify signature using public key)
// arg1: method: "MD5", "SHA1", "SHA256", "SHA512"
// arg2: public key file path
// arg3: signature content
// arg4: signature input format: bin, hex, b64
// arg5: content
// e.g.: poco_lib verify <MD5/SHA1/SHA265/SHA512> <public_key_file_path> <signature> <signFormat:bin/hex/b64> <content>

int main(int argc, char **argv) {
  pocolib_ex::profiler::Instrumentor::Get().BeginSession("Profile");
  // check only one input:
  auto [wellParsed, usecase_ptr, content] = pocolib_ex::usecase::UsecaseFactory::retrieveUseCase(argc, argv);
  if (wellParsed) {
    std::cout << usecase_ptr->execute(content) << "\n";
  }
  pocolib_ex::profiler::Instrumentor::Get().EndSession();
  return 0;
}
