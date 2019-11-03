//
// Created by rbroggi on 11/3/19.
//

#include <Poco/Crypto/RSAKey.h>
#include <Poco/Crypto/CipherFactory.h>
#include <Poco/Crypto/Cipher.h>
#include "Encrypt.h"

namespace pocolib_ex {
namespace usecase {

using namespace std::string_literals;

Encrypt::Encrypt(const std::string &pub_key_file_path, Format out_format) : pub_key_file_path_(pub_key_file_path), out_format(out_format) {}

std::string Encrypt::execute(const std::string &content) {
  Poco::Crypto::Cipher* cypher_ptr = Poco::Crypto::CipherFactory::defaultFactory()
      .createCipher(Poco::Crypto::RSAKey(pub_key_file_path_), RSAPaddingMode::RSA_PADDING_PKCS1);
  if (cypher_ptr != nullptr) {
    if (out_format == Format::BIN) {
      return cypher_ptr->encryptString(content, Poco::Crypto::Cipher::ENC_NONE);
    } else if (out_format == Format::HEX) {
      return cypher_ptr->encryptString(content, Poco::Crypto::Cipher::ENC_BINHEX);
    } else if (out_format == Format::BASE_64) {
      return cypher_ptr->encryptString(content, Poco::Crypto::Cipher::ENC_BASE64);
    }
  }
  return ""s;
}

}
}
