//
// Created by rbroggi on 11/3/19.
//

#include "Sign.h"
#include <HexAndBase64Utils.h>

using namespace std::string_literals;
pocolib_ex::usecase::Sign::Sign(const std::string& aHashAlgo,
                                const std::string &private_key_file_path,
                                const std::string &pwd,
                                pocolib_ex::usecase::Format format)
    : digest_engine(Poco::Crypto::RSAKey("", private_key_file_path, pwd), aHashAlgo),
      out_format(format) {}

std::string pocolib_ex::usecase::Sign::execute(const std::string &content) {
  digest_engine.update(content);
  std::string digestHex = Poco::DigestEngine::digestToHex(digest_engine.signature());
  if (out_format == Format::BIN) {
    return pocolib_ex::fromHex(digestHex);
  } else if (out_format == Format::HEX) {
    return digestHex;
  } else if (out_format == Format::BASE_64) {
    return pocolib_ex::toBase64(digestHex);
  }
  return "Error!"s;
}
