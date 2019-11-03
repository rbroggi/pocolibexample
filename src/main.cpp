#include <Poco/MD5Engine.h>
#include <Poco/DigestStream.h>
#include <Poco/Crypto/RSADigestEngine.h>
#include <iostream>
#include <HexAndBase64Utils.h>

namespace crypto = Poco::Crypto;

int main(int argc, char **argv) {
  // check only one input:
  if (argc != 2) {
    std::cerr << "Wrong number of arguments.\n Usage:\n " << argv[0] << " <payload>\n";
    return 1;
  }

  // calculate md5 input
  std::string input{argv[1]};
  Poco::MD5Engine md5;
  Poco::DigestOutputStream ds(md5);
  ds << input;
  ds.close();
  std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;

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
