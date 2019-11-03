//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include <string>

namespace pocolib_ex {
namespace usecase {
class UseCase {
 public:
  virtual std::string execute(const std::string &content) = 0;

  virtual ~UseCase() = default;
};
}
}


