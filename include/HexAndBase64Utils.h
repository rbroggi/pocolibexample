//
// Created by rbroggi on 11/3/19.
//

#pragma once

#include <string>

namespace pocolib_ex {

std::string toBase64(const std::string& input);

std::string fromBase64(const std::string &input);

std::string toHex(const std::string &input);

std::string fromHex(const std::string &input);

}
