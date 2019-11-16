//
// Created by rbroggi on 11/3/19.
//

#include "Verify.h"
#include <HexAndBase64Utils.h>
#include <iostream>
pocolib_ex::usecase::Verify::Verify(
    const std::string& aHashAlgo,
    const std::string &public_key_file_path,
    const std::string &signature, pocolib_ex::usecase::Format in_format)
    : digest_engine(Poco::Crypto::RSAKey(public_key_file_path), aHashAlgo), signature(signature), in_format(in_format) {
}

std::string pocolib_ex::usecase::Verify::execute(const std::string &content) {

  // convert signature to digest format (input->hex->digest)
  Poco::DigestEngine::Digest aSignatureDigest;
  if (in_format == Format::BIN) {
    aSignatureDigest =
        Poco::DigestEngine::digestFromHex(pocolib_ex::toHex(signature));
  } else if (in_format == Format::HEX) {
    aSignatureDigest = Poco::DigestEngine::digestFromHex(signature);
  } else {
    aSignatureDigest =
        Poco::DigestEngine::digestFromHex(pocolib_ex::fromFormatToFormat(
            usecase::Format::BASE_64, usecase::Format::HEX, signature));
  }
  digest_engine.update(content);
  if (digest_engine.verify(aSignatureDigest)) {
    return "Verified";
  }
  return "Could not verify signature.";
}
