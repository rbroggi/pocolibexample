//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include "UseCase.h"
#include "Format.h"

// enc (encrypt content using RSA public key)
// arg1: publicKey file
// arg2: output format: bin, hex, b64
// arg3: content
// e.g.: poco_lib enc <publicKeyPath> <content>
namespace pocolib_ex {
namespace usecase {

class Encrypt : public UseCase {

 public:
  Encrypt(const std::string &pub_key_file_path, Format out_format);

  std::string execute(const std::string &content) override;

  virtual ~Encrypt() = default;

 private:
  std::string pub_key_file_path_;
  Format out_format;

};
}
}



