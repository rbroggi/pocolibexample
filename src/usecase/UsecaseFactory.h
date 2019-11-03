//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include "UseCase.h"
#include "Format.h"
#include <memory>

namespace pocolib_ex {
namespace usecase {
class UsecaseFactory {

 public:
  static std::tuple<bool, std::unique_ptr<UseCase>, std::string> retrieveUseCase(int argc, char **argv);
 private:
  static bool isValidHash(const std::string& candidate);
  static Format retrieveFormat(const std::string& format_str);
  static bool fileExist(const std::string& name);

};
}
}




