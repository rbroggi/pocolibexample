//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include "Format.h"
#include "UseCase.h"

// enc (encrypt content using RSA public key)
// arg1: privateKey file
// arg2: pwd
// arg3: input format: bin, hex, b64
// arg4: content
// e.g.: poco_lib dec <privateKeyPath> <pwd> <inputFormat> <content>
namespace pocolib_ex {
namespace usecase {
class Decrypt : public UseCase {
public:
  Decrypt(const std::string &private_key_file_path, const std::string &pwd,
          Format out_format);
  std::string execute(const std::string &content) override;

private:
private:
  std::string private_key_file_path;
  std::string pwd;
  Format out_format;

};
}
}



