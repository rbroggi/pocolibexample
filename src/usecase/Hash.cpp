//
// Created by rbroggi on 11/3/19.
//

#include <HexAndBase64Utils.h>
#include "Hash.h"

std::string pocolib_ex::usecase::Hash::execute(const std::string &content) {
  digest_engine.update(content);
  return fromFormatToFormat(Format::HEX, format, Poco::DigestEngine::digestToHex(digest_engine.digest()));
}

pocolib_ex::usecase::Hash::Hash(const std::string &hash_type, const Format format) : digest_engine(hash_type), format(format) {}


