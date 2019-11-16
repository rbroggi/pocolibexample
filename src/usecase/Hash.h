//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include <Poco/Crypto/DigestEngine.h>
#include "UseCase.h"
#include "Format.h"

namespace pocolib_ex {
namespace usecase {
class Hash : public UseCase {

 public:

  Hash(const std::string &hash_type, const Format format);

  std::string execute(const std::string &content) override;

 private:
  Poco::Crypto::DigestEngine digest_engine;
  Format format;

};
}
}



