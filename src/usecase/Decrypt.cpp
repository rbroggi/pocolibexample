//
// Created by rbroggi on 11/3/19.
//

#include "Decrypt.h"
#include <Macros.h>
#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>
#include <Poco/Crypto/RSAKey.h>

using namespace std::string_literals;

pocolib_ex::usecase::Decrypt::Decrypt(const std::string &private_key_file_path,
                                      const std::string &pwd,
                                      pocolib_ex::usecase::Format out_format)
    : private_key_file_path(private_key_file_path), pwd(pwd),
      out_format(out_format) {}

std::string pocolib_ex::usecase::Decrypt::execute(const std::string &content) {
  PROFILE_FUNCTION();
  Poco::Crypto::Cipher* cypher_ptr = Poco::Crypto::CipherFactory::defaultFactory()
      .createCipher(Poco::Crypto::RSAKey("", private_key_file_path, pwd), RSAPaddingMode::RSA_PADDING_PKCS1);
  if (cypher_ptr != nullptr) {
    if (out_format == Format::BIN) {
      return cypher_ptr->decryptString(content, Poco::Crypto::Cipher::ENC_NONE);
    } else if (out_format == Format::HEX) {
      return cypher_ptr->decryptString(content, Poco::Crypto::Cipher::ENC_BINHEX);
    } else if (out_format == Format::BASE_64) {
      return cypher_ptr->decryptString(content, Poco::Crypto::Cipher::ENC_BASE64);
    }
  }
  return "Error!"s;
}
