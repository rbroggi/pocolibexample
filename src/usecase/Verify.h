//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include "Format.h"
#include "UseCase.h"
#include <Poco/Crypto/RSADigestEngine.h>
namespace pocolib_ex {
namespace usecase {
// e.g.: poco_lib verify <MD5/SHA1/SHA265/SHA512> <public_key_file_path> <signature> <signFormat:bin/hex/b64> <content>
class Verify : public UseCase {
public:
  Verify(const std::string& aHashAlgo,
         const std::string &public_key_file_path,
         const std::string &signature, Format in_format);

  std::string execute(const std::string &content) override;

private:
  Poco::Crypto::RSADigestEngine digest_engine;
  std::string signature;
  Format in_format;

};
} // namespace usecase
} // namespace pocolib_ex
