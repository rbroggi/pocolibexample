#include <Poco/MD5Engine.h>
#include <Poco/DigestStream.h>
#include <Poco/Crypto/RSADigestEngine.h>
#include <iostream>
#include <HexAndBase64Utils.h>
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
  // check only one input:
  auto [wellParsed, usecase_ptr, content] = pocolib_ex::usecase::UsecaseFactory::retrieveUseCase(argc, argv);
  if (wellParsed) {
    std::cout << usecase_ptr->execute(content) << "\n";
  }

  // calculate md5 input
  std::string input{"abcde"};

  //Creation of RSA key to sign and verify payload
  crypto::RSAKey rsa_key{crypto::RSAKey::KL_4096, crypto::RSAKey::EXP_LARGE};
  //Creation of digest in SHA256 format for signature
  crypto::RSADigestEngine digest_engine{rsa_key,"SHA256"};
  digest_engine.update(input);
  //Creation of digest in SHA256 format for signature
  crypto::DigestEngine digest_engine_sha256{"SHA256"};
  digest_engine_sha256.update(input);

  //Checks the SHA256 is the same for both DigestEngines
  std::string digest_hex = Poco::DigestEngine::digestToHex(digest_engine_sha256.digest());
  std::cout << digest_hex << std::endl;

  //Decode from HEX to binary and convert to base64:
  std::string digest_bin = pocolib_ex::fromHex(digest_hex);
  std::cout << pocolib_ex::toHex(digest_bin) << std::endl;
  std::cout << pocolib_ex::toBase64(digest_bin) << std::endl;

  //Sign the input with the RSA Digest
  std::cout << Poco::DigestEngine::digestToHex(digest_engine.signature()) << std::endl;
  std::cout << std::boolalpha << digest_engine.verify(digest_engine.signature()) << std::endl;


  // Creates a 256-bit AES cipher
//  crypto::Cipher* pCipher = factory.createCipher(crypto::CipherKey("aes-256"));

  return 0;
}
