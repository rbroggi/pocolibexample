//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include "Format.h"
#include "UseCase.h"
#include <Poco/Crypto/DigestEngine.h>
#include <Poco/Crypto/RSADigestEngine.h>

namespace pocolib_ex {
namespace usecase {
class Sign : public UseCase {
public:
  Sign(const std::string& aHashAlgo,
       const std::string &private_key_file_path,
       const std::string &pwd,
       Format format);

  std::string execute(const std::string &content) override;

private:
  Poco::Crypto::RSADigestEngine digest_engine;
  Format out_format;
};

} // namespace usecase
} // namespace pocolib_ex
